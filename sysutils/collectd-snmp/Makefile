# $NetBSD: Makefile,v 1.6 2020/01/18 21:50:53 jperkin Exp $

COLLECTD_PACKAGE=	snmp

COMMENT=		Statistics collection daemon - snmp plugin
PKGREVISION=		3

.include "../../sysutils/collectd/Makefile.common"

CONFIGURE_ARGS+=	--with-libnetsnmp=${BUILDLINK_PREFIX.net-snmp}/bin/net-snmp-config

.include "../../net/net-snmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
