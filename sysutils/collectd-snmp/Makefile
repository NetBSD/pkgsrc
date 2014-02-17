# $NetBSD: Makefile,v 1.1 2014/02/17 11:21:55 fhajny Exp $

COLLECTD_PACKAGE=	snmp

COMMENT=		Statistics collection daemon - snmp plugin

.include "../../sysutils/collectd/Makefile.common"

CONFIGURE_ARGS+=	--with-libnetsnmp=${BUILDLINK_PREFIX.net-snmp}/bin/net-snmp-config

.include "../../net/net-snmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
