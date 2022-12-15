# $NetBSD: Makefile,v 1.3 2022/12/15 10:09:44 wiz Exp $

SYSLOG_MOD=		snmp
SYSLOG_MOD_DIR=		afsnmp
COMMENT=		Syslog-ng AFSNMP module

.include "../../sysutils/syslog-ng/module.mk"

CONFIGURE_ARGS+=	--enable-afsnmp

.include "../../net/net-snmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
