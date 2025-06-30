# $NetBSD: Makefile,v 1.2 2025/06/30 11:01:49 jperkin Exp $

.include "../../net/powerdns/backend.mk"

PKGNAME=		${DISTNAME:S/pdns/powerdns-geoip/}
COMMENT=		GeoIP backend module for PowerDNS

CONFIGURE_ARGS+=	--with-dynmodules="geoip"

.include "../../net/GeoIP/buildlink3.mk"
.include "../../textproc/yaml-cpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
