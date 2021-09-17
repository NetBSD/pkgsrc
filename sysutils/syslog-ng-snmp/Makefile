# $NetBSD: Makefile,v 1.1 2021/09/17 09:41:44 wiz Exp $

SYSLOG_MOD=		snmp
SYSLOG_MOD_DIR=		afsnmp
COMMENT=		Syslog-ng AFSNMP module

.include "../../sysutils/syslog-ng/module.mk"

CONFIGURE_ARGS+=	--enable-afsnmp

.include "../../net/net-snmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
