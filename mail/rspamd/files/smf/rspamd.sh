#!@SMF_METHOD_SHELL@
#
# $NetBSD: rspamd.sh,v 1.1 2020/01/06 12:06:08 jperkin Exp $
#

. /lib/svc/share/smf_include.sh

if [ ! -d @VARBASE@/run/rspamd ]; then
	@MKDIR@ @VARBASE@/run/rspamd
	@CHMOD@ 0750 @VARBASE@/run/rspamd
	@CHOWN@ @RSPAMD_USER@:@RSPAMD_GROUP@ @VARBASE@/run/rspamd
fi

@PREFIX@/bin/rspamd "$@"
