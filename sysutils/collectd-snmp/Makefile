# $NetBSD: Makefile,v 1.2 2016/03/05 11:29:29 jperkin Exp $

COLLECTD_PACKAGE=	snmp

COMMENT=		Statistics collection daemon - snmp plugin
PKGREVISION=		1

.include "../../sysutils/collectd/Makefile.common"

CONFIGURE_ARGS+=	--with-libnetsnmp=${BUILDLINK_PREFIX.net-snmp}/bin/net-snmp-config

.include "../../net/net-snmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
