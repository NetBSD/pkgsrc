# $NetBSD: Makefile,v 1.3 2022/12/15 10:09:43 wiz Exp $

SYSLOG_MOD=		geoip2
SYSLOG_MOD_TARGET=	geoip2-plugin
COMMENT=		Syslog-ng GeoIP module

.include "../../sysutils/syslog-ng/module.mk"

CONFIGURE_ENV+=		GEOIP_LIBS="-L${BUILDLINK_PREFIX.GeoIP}/lib -lGeoIP"

.include "../../geography/libmaxminddb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
