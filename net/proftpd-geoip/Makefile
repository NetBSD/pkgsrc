# $NetBSD: Makefile,v 1.1 2015/09/25 10:01:36 wiedi Exp $

.include "../../net/proftpd/Makefile.module"

PROFTPD_MOD=	geoip
PKGNAME=	${DISTNAME:S/proftpd/proftpd-${PROFTPD_MOD}/}
COMMENT=	Geolocation module for proftpd

CONFIGURE_ARGS+=	--with-shared=mod_geoip

.include "../../net/GeoIP/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
