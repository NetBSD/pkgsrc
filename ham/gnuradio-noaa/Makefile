# $NetBSD: Makefile,v 1.4 2016/10/07 18:25:55 adam Exp $

PKGNAME=	gnuradio-noaa-${VERSION}
PKGREVISION=	1
COMMENT=	NOAA, Weather Satellite Reception module of GNU Radio

.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_ARGS+=	-DENABLE_GR_NOAA=ON

.include	"../../mk/bsd.pkg.mk"
