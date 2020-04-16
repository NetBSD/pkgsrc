#!@SMF_METHOD_SHELL@
#
# $NetBSD: radiusd.sh,v 1.1 2020/04/16 15:49:30 jperkin Exp $
#

. /lib/svc/share/smf_include.sh

if [ ! -d @VARBASE@/run/radiusd ]; then
	@MKDIR@ @VARBASE@/run/radiusd
	@CHMOD@ 0750 @VARBASE@/run/radiusd
	@CHOWN@ @RADIUS_USER@:@RADIUS_GROUP@ @VARBASE@/run/radiusd
fi

@PREFIX@/sbin/radiusd "$@"
