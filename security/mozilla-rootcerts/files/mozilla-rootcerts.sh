#!/bin/sh
#
# $NetBSD: mozilla-rootcerts.sh,v 1.20 2020/03/30 16:38:03 gdt Exp $
#
# This script is meant to be used as follows:
#
#	# cd /etc/openssl/certs
#	# mozilla-rootcerts extract
#	# mozilla-rootcerts rehash
#

: ${AWK=@AWK@}
: ${DATADIR=@DATADIR@}
: ${ECHO=@ECHO@}
: ${EXPR=@EXPR@}
: ${LN=@LN@}
: ${LS=@LS@}
: ${MKDIR=@MKDIR@}
: ${OPENSSL=@OPENSSL@}
: ${PREFIX=@PREFIX@}
: ${SSLDIR=@SSLDIR@}
: ${RM=@RM@}

self="${PREFIX}/sbin/mozilla-rootcerts"
certfile="${DATADIR}/certdata.txt"
certdir=${SSLDIR}/certs
destdir=

usage()
{
	${ECHO} 1>&2 "usage: $self [-d destdir] [-f certfile] extract|rehash|install"
	exit $1
}

while [ $# -gt 0 ]; do
	case "$1" in
	-d)	destdir="$2"; shift 2;;
	-f)	certfile="$2"; shift 2 ;;
	--)	shift; break ;;
	-*)	${ECHO} 1>&2 "$self: unknown option -- $1"
		usage 128 ;;
	*)	break ;;
	esac
done

[ $# -eq 1 ] || usage 128

action="$1"; shift

#
#	link_hash pemtype pemfile
#
#	Link a certificate or CRL to its subject name hash value.
#	Each hash is of the form <hash>.<n> for certificates and
#	<hash>.r<n> for CRLs, where n is an integer.  If the hash
#	value already exists, then we need to up the value of n, unless
#	it's a duplicate, in which case we skip the link.  We check
#	for duplicates by comparing fingerprints.
#
link_hash()
{
	_pemtype="$1"; _pemfile="$2"; shift 2

	_hash=`${OPENSSL} "$_pemtype" -hash -noout -in "$_pemfile"`
	_fprint=`${OPENSSL} "$_pemtype" -fingerprint -noout -in "$_pemfile"`
	_suffix=0
	while [ 1 = 1 ] ; do
		case $_pemtype in
		crl)	_hashfile="$_hash.r$_suffix" ;;
		x509|*)	_hashfile="$_hash.$_suffix" ;;
		esac
		if [ ! -f "$_hashfile" ]; then
			${ECHO} "$_pemfile => $_hashfile"
			${LN} -sf "$_pemfile" "$_hashfile"
			break
		fi
		_fprintold=`${OPENSSL} "$_pemtype" -fingerprint -noout -in "$_hashfile"`
		if [ "$_fprint" = "$_fprintold" ]; then
			${ECHO} 1>&2 "WARNING: Skipping duplicate certificate $_pemfile"
			return
		fi
		_suffix=`${EXPR} $_suffix + 1`
	done
}

case $action in
rehash)
	# Delete any existing symbolic links.
	${LS} | while read entry; do
		[ ! -h "$entry" ] || ${RM} -f "$entry"
	done

	${LS} | while read pemfile; do
		case $pemfile in
		*.pem)	;;
		*)	continue ;;
		esac
		pemtype=
		while read line; do
			case $line in
			"-----BEGIN CERTIFICATE-----"|\
			"-----BEGIN X509 CERTIFICATE-----"|\
			"-----BEGIN TRUSTED CERTIFICATE-----")
				pemtype=x509
				break
				;;
			"-----BEGIN X509 CRL-----")
				pemtype=crl
				break
				;;
			esac
		done < "$pemfile"
		case $pemtype in
		x509|crl)
			link_hash "$pemtype" "$pemfile"
			;;
		*)
			${ECHO} 1>&2 "WARNING: $pemfile does not contain a certificate or CRL: skipping"
			continue
			;;
		esac
	done
	;;

extract)
	#
	# Certificates in octal-encoded DER format are delimited by
	# "CKA_VALUE MULTILINE_OCTAL"/"END" pairs.  Convert them into
	# long character strings and pipe them through openssl to
	# convert from DER to PEM format.
	#
	# The resulting PEM format certificates are saved as
	# "mozilla-rootcert-<n>.pem" in the current working directory.
	#
	# gawk will corrupt the output data stream in multibyte locales,
	# so force the locale to "C". 
	# Setting just LANG is not enough. LC_ALL has higher priority.
	#
	cat "$certfile" | LC_ALL=C LANG=C ${AWK} -v OPENSSL=${OPENSSL} '
	function base8to10(o,	octal, decimal, power, i, n) {
		decimal = 0
		n = split(o, octal, "")
		while (n > 0) {
			power = 1
			for (i = 1; i < n; i++)
				power *= 8
			decimal += octal[4-n] * power
			n--
		}
		return decimal
	}

	BEGIN {
		filenum = 0
		while (getline) {
			if ($0 !~ /^CKA_VALUE MULTILINE_OCTAL/) continue

			filename = "mozilla-rootcert-" filenum ".pem"
			filenum++
			cmd = OPENSSL " x509 -inform der -outform pem -text >" filename
			print filename
			while (getline) {
				if ($0 ~ /^END/) break
				n = split($0, line, "\\")
				for (i = 2; i <= n; i++) {
					printf("%c",  base8to10(line[i])) | cmd
				}
			}
			close(cmd)
			# kill untrusted certificates (not clean, but the script which comes
			# with "curl" works the same way)
			untrusted = 0
			# Read lines only until we find the trust data
			# following the certificate, then stop.
			while (getline) {
				if ($0 ~ /^CKA_TRUST_SERVER_AUTH/) break
			}
			# Test the result for untrusted status
			if ($0 ~ /^CKA_TRUST_SERVER_AUTH.*CK_TRUST.*CKT_NSS_NOT_TRUSTED$/)
				untrusted = 1
			if ($0 ~ /^CKA_TRUST_SERVER_AUTH.*CK_TRUST.*CKT_NETSCAPE_UNTRUSTED$/)
				untrusted = 1

			if (untrusted) {
				print filename " untrusted"
				system("rm -f " filename)
			}
		}
	}'
	;;
install)
	# ${WHATEVER}/etc/openssl/certs should exist, but an
	# install/removal cycle of mozilla-rootcerts-openssl might have removed it.
	if [ ! -d $destdir$certdir ]; then
		${ECHO} 1>&2 "WARNING: $destdir$certdir does not exist.  Creating it."
		${MKDIR} -p $destdir$certdir
	fi
	cd $destdir$certdir
	if [ -n "`${LS}`" ]; then
		# \todo Explain why this must fail if the user has
		# installed certificates from other than the mozilla
		# default root set.
		${ECHO} 1>&2 "ERROR: $destdir$certdir already contains certificates, aborting."
		exit 1
	fi
	set -e
	$self extract
	$self rehash
	set +e
	# \todo Explain why if we are willing to write
	# ca-certificates.crt, we are not willing to remove and
	# re-create it.  Arguably install should be idempotent without
	# error.
	if [ -e $destdir$certdir/ca-certificates.crt ]; then
		${ECHO} 1>&2 "ERROR: $destdir$certdir/ca-certificates.crt already exists, aborting."
		exit 1
	fi
	set -e
	# \todo This is appparently for users of gnutls, but it is not
	# clear where it should be and why.  In particular, this file
	# should perhaps be created at package build time and be
	# managed by pkgsrc.
	cat $destdir$certdir/*.pem > $destdir$certdir/ca-certificates.crt
esac
