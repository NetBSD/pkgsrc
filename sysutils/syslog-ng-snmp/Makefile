# $NetBSD: Makefile,v 1.2 2021/12/08 16:06:38 adam Exp $

SYSLOG_MOD=		snmp
SYSLOG_MOD_DIR=		afsnmp
COMMENT=		Syslog-ng AFSNMP module
PKGREVISION=		1

.include "../../sysutils/syslog-ng/module.mk"

CONFIGURE_ARGS+=	--enable-afsnmp

.include "../../net/net-snmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
