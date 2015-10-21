#!/sbin/sh
# $NetBSD: unbound.sh,v 1.1 2015/10/21 21:30:14 joerg Exp $
. /lib/svc/share/smf_include.sh

if [ ! -d @VARBASE@/run/unbound ]; then
	@MKDIR@ @VARBASE@/run/unbound
	@CHMOD@ 0750 @VARBASE@/run/unbound
	@CHOWN@ @UNBOUND_USER@:@UNBOUND_GROUP@ @VARBASE@/run/unbound
fi

@PREFIX@/sbin/unbound -c "$1"
