# $NetBSD: Makefile,v 1.2 2015/04/17 15:53:07 adam Exp $

PKGNAME=	gnuradio-channels-${VERSION}
PKGREVISION=	1
COMMENT=	Signal processing blocks to simulate channel models of gnuradio

.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_ARGS+=	-DENABLE_GR_CHANNELS=ON

.include	"../../mk/bsd.pkg.mk"
