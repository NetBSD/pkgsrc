# $NetBSD: Makefile,v 1.1 2015/10/29 16:34:14 fhajny Exp $

SYSLOG_MOD=		geoip
SYSLOG_MOD_TARGET=	geoip-plugin
COMMENT=		Syslog-ng GeoIP module

.include "../../sysutils/syslog-ng/Makefile.module"

CONFIGURE_ENV+=		GEOIP_LIBS="-L${BUILDLINK_PREFIX.GeoIP}/lib -lGeoIP"

.include "../../net/GeoIP/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
