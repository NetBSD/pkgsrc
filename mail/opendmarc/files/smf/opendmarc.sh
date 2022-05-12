#!@SMF_METHOD_SHELL@
#
# $NetBSD: opendmarc.sh,v 1.1 2022/05/12 13:49:28 jperkin Exp $
#

. /lib/svc/share/smf_include.sh

if [ ! -d @VARBASE@/run/opendmarc ]; then
	@MKDIR@ @VARBASE@/run/opendmarc
	@CHMOD@ 0750 @VARBASE@/run/opendmarc
	@CHOWN@ @OPENDMARC_USER@:@OPENDMARC_GROUP@ @VARBASE@/run/opendmarc
fi

@PREFIX@/sbin/opendmarc "$@"
