# $NetBSD: Makefile,v 1.2 2021/12/08 16:06:38 adam Exp $

SYSLOG_MOD=		geoip2
SYSLOG_MOD_TARGET=	geoip2-plugin
COMMENT=		Syslog-ng GeoIP module
PKGREVISION=		1

.include "../../sysutils/syslog-ng/module.mk"

CONFIGURE_ENV+=		GEOIP_LIBS="-L${BUILDLINK_PREFIX.GeoIP}/lib -lGeoIP"

.include "../../geography/libmaxminddb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
