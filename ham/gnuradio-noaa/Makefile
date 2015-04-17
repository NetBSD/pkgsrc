# $NetBSD: Makefile,v 1.2 2015/04/17 15:53:08 adam Exp $

PKGNAME=	gnuradio-noaa-${VERSION}
PKGREVISION=	1
COMMENT=	NOAA, Weather Satellite Reception module of GNU Radio

.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_ARGS+=	-DENABLE_GR_NOAA=ON

.include	"../../mk/bsd.pkg.mk"
