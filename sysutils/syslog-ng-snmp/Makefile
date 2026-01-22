# $NetBSD: Makefile,v 1.5 2026/01/22 10:07:16 wiz Exp $

SYSLOG_MOD=		snmp
SYSLOG_MOD_DIR=		afsnmp
COMMENT=		Syslog-ng AFSNMP module
PKGREVISION=		1

# error: ISO C90 forbids mixed declarations and code [-Werror=declaration-after-statement]
BUILDLINK_TRANSFORM+=	rm:-Werror=declaration-after-statement

.include "../../sysutils/syslog-ng/module.mk"

CONFIGURE_ARGS+=	--enable-afsnmp

.include "../../net/net-snmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
