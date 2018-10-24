#!@SH@
#
# $NetBSD: ofmipd-with-user-cdb.sh,v 1.1 2018/10/24 16:28:28 schmonz Exp $
#
# @PKGNAME@ wrapper to let ofmipd users control their own CDB
# of address rewriting rules.
# Requires qmail-acceptutils.
#

user_cdb="$HOME/.ofmipd/rules.cdb"

if [ -f "${user_cdb}" ]; then
	exec @PREFIX@/bin/ofmipd "${user_cdb}" "$@"
else
	exec @PREFIX@/bin/ofmipd "$@"
fi
