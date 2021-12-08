# $NetBSD: Makefile,v 1.31 2021/12/08 16:05:08 adam Exp $

PKGNAME=	gnuradio-channels-${VERSION}
PKGREVISION=	3
COMMENT=	Signal processing blocks to simulate channel models of GNU Radio

.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_ARGS+=	-DENABLE_GR_CHANNELS=ON
CMAKE_ARGS+=	-DENABLE_GRC=ON

PLIST_MINUS+=	companion

.include	"../../mk/bsd.pkg.mk"
