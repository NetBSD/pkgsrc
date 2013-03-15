#!/bin/sh
#
# $NetBSD: mozilla-rootcerts.sh,v 1.5 2013/03/15 16:14:55 bsiegert Exp $
#
# This script is meant to be used as follows:
#
#	# cd /etc/openssl/certs
#	# mozilla-rootcerts extract
#	# mozilla-rootcerts rehash
#

: ${AWK=@AWK@}
: ${ECHO=@ECHO@}
: ${EXPR=@EXPR@}
: ${LN=@LN@}
: ${LS=@LS@}
: ${MKDIR=@MKDIR@}
: ${OPENSSL=@OPENSSL@}
: ${SSLDIR=@SSLDIR@}
: ${RM=@RM@}

self="mozilla-rootcerts"
certfile="@DATADIR@/certdata.txt"
certdir="/etc/ssl/certs"

usage()
{
	${ECHO} 1>&2 "usage: $self [-f certfile] extract|rehash|install"
	exit $1
}

while [ $# -gt 0 ]; do
	case "$1" in
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
	cat "$certfile" | ${AWK} -v OPENSSL=${OPENSSL} '
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
			while (getline) {
				if ($0 ~ /^#$/) break
				if ($0 ~ /^CKA_TRUST_SERVER_AUTH.*CK_TRUST.*CKT_NSS_NOT_TRUSTED$/)
					untrusted = 1
				if ($0 ~ /^CKA_TRUST_SERVER_AUTH.*CK_TRUST.*CKT_NETSCAPE_UNTRUSTED$/)
					untrusted = 1
			}
			if (untrusted) {
				print filename " untrusted"
				system("rm -f " filename)
			}
		}
	}'
	;;
install)
	if [ ! -d $SSLDIR ]; then
		${ECHO} 1>&2 "ERROR: $SSLDIR does not exist, aborting."
		exit 1
	fi
	cd $SSLDIR
	if [ -n "`${LS}`" ]; then
		${ECHO} 1>&2 "ERROR: $SSLDIR already contains certificates, aborting."
		exit 1
	fi
	set -e
	$self extract
	$self rehash
	set +e
	if [ -d $certdir ]; then
		${ECHO} 1>&2 "ERROR: $certdir already exists, aborting."
		exit 1
	fi
	set -e
	$MKDIR $certdir
	cat $SSLDIR/*.pem > $certdir/ca-certificates.crt
esac
