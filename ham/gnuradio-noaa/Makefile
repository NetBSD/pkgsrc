# $NetBSD: Makefile,v 1.13 2018/12/13 19:52:03 adam Exp $

PKGNAME=	gnuradio-noaa-${VERSION}
PKGREVISION=	2
COMMENT=	NOAA, Weather Satellite Reception module of GNU Radio

.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_ARGS+=	-DENABLE_GR_NOAA=ON

.include	"../../mk/bsd.pkg.mk"
