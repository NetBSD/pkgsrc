# $NetBSD: Makefile,v 1.10 2018/04/29 21:31:47 adam Exp $

PKGNAME=	gnuradio-noaa-${VERSION}
PKGREVISION=	4
COMMENT=	NOAA, Weather Satellite Reception module of GNU Radio

.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_ARGS+=	-DENABLE_GR_NOAA=ON

.include	"../../mk/bsd.pkg.mk"
