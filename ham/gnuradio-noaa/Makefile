# $NetBSD: Makefile,v 1.1 2014/10/13 12:51:09 mef Exp $

PKGNAME=	gnuradio-noaa-${VERSION}
COMMENT=	NOAA, Weather Satellite Reception module of GNU Radio

.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_ARGS+=	-DENABLE_GR_NOAA=ON

.include	"../../mk/bsd.pkg.mk"
