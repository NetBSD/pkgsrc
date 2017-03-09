# $NetBSD: Makefile,v 1.1 2017/03/09 13:50:07 fhajny Exp $

.include "../../net/powerdns/Makefile.backend"

PKGNAME=		${DISTNAME:S/pdns/powerdns-geoip/}
COMMENT=		GeoIP backend module for PowerDNS

CONFIGURE_ARGS+=	--with-dynmodules="geoip"

.include "../../net/GeoIP/buildlink3.mk"
.include "../../textproc/yaml-cpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
