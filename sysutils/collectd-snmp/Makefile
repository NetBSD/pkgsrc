# $NetBSD: Makefile,v 1.9 2023/10/24 22:11:05 wiz Exp $

COLLECTD_PACKAGE=	snmp

COMMENT=		Statistics collection daemon - snmp plugin
PKGREVISION=		1

.include "../../net/net-snmp/buildlink3.mk"
COLLECTD_LIB.netsnmp=	${BUILDLINK_PREFIX.net-snmp}/bin/net-snmp-config

.include "../../sysutils/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
