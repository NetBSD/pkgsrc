#!/bin/sh
#
# $NetBSD: mozilla-rootcerts.sh,v 1.1.1.1 2007/09/20 20:02:53 jlam Exp $
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
: ${OPENSSL=@OPENSSL@}
: ${RM=@RM@}

self="mozilla-rootcerts"
certfile="@DATADIR@/certdata.txt"

usage()
{
	${ECHO} 1>&2 "usage: $self [-f certfile] extract|rehash"
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
		suffix=`${EXPR} $suffix + 1`
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
	function join(array, start, end, separator,	result, i) {
		result = array[start]
		for (i = start + 1; i <= end; i++)
			result = result separator array[i]
		return result
	}

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
			D = 0
			if ($0 !~ /^CKA_VALUE MULTILINE_OCTAL/) continue

			filename = "mozilla-rootcert-" filenum ".pem"
			filenum++
			cmd = OPENSSL " x509 -inform der -outform pem -text >" filename
			print filename
			while (getline) {
				if ($0 ~ /^END/) break
				n = split($0, line, "\\")
				for (i = 2; i <= n; i++) {
					der[D++] = sprintf("%c", base8to10(line[i]))
				}
			}
			printf("%s", join(der, 0, D, "")) | cmd
			close(cmd)
		}
	}'
	;;
esac
