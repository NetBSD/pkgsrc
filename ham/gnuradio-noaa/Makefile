# $NetBSD: Makefile,v 1.16 2019/08/22 12:23:22 ryoon Exp $

PKGNAME=	gnuradio-noaa-${VERSION}
PKGREVISION=	2
COMMENT=	NOAA, Weather Satellite Reception module of GNU Radio

.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_ARGS+=	-DENABLE_GR_NOAA=ON

.include	"../../mk/bsd.pkg.mk"
