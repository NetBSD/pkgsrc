# $NetBSD: Makefile,v 1.6 2026/11/27 11:01:44 adam Exp $

SYSLOG_MOD=		snmp
SYSLOG_MOD_DIR=		afsnmp
COMMENT=		Syslog-ng AFSNMP module

# error: ISO C90 forbids mixed declarations and code [-Werror=declaration-after-statement]
BUILDLINK_TRANSFORM+=	rm:-Werror=declaration-after-statement

.include "../../sysutils/syslog-ng/module.mk"

CONFIGURE_ARGS+=	--enable-afsnmp

.include "../../net/net-snmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
