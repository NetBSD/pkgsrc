# $NetBSD: Makefile,v 1.9 2018/01/01 21:18:34 adam Exp $

PKGNAME=	gnuradio-channels-${VERSION}
PKGREVISION=	3
COMMENT=	Signal processing blocks to simulate channel models of GNU Radio

.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_ARGS+=	-DENABLE_GR_CHANNELS=ON

.include	"../../mk/bsd.pkg.mk"
