# $NetBSD: Makefile,v 1.12 2018/08/16 18:54:54 adam Exp $

PKGNAME=	gnuradio-channels-${VERSION}
PKGREVISION=	1
COMMENT=	Signal processing blocks to simulate channel models of GNU Radio

.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_ARGS+=	-DENABLE_GR_CHANNELS=ON

.include	"../../mk/bsd.pkg.mk"
