# $NetBSD: Makefile,v 1.15 2019/07/01 04:08:24 ryoon Exp $

PKGNAME=	gnuradio-noaa-${VERSION}
PKGREVISION=	1
COMMENT=	NOAA, Weather Satellite Reception module of GNU Radio

.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_ARGS+=	-DENABLE_GR_NOAA=ON

.include	"../../mk/bsd.pkg.mk"
