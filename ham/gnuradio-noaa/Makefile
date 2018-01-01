# $NetBSD: Makefile,v 1.9 2018/01/01 21:18:35 adam Exp $

PKGNAME=	gnuradio-noaa-${VERSION}
PKGREVISION=	3
COMMENT=	NOAA, Weather Satellite Reception module of GNU Radio

.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_ARGS+=	-DENABLE_GR_NOAA=ON

.include	"../../mk/bsd.pkg.mk"
