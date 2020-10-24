# $NetBSD: Makefile,v 1.8 2020/10/24 22:39:48 wiz Exp $

COLLECTD_PACKAGE=	snmp

COMMENT=		Statistics collection daemon - snmp plugin

.include "../../net/net-snmp/buildlink3.mk"
COLLECTD_LIB.netsnmp=	${BUILDLINK_PREFIX.net-snmp}/bin/net-snmp-config

.include "../../sysutils/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
