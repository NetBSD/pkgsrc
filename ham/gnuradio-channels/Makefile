# $NetBSD: Makefile,v 1.19 2020/08/18 17:58:03 leot Exp $

PKGNAME=	gnuradio-channels-${VERSION}
PKGREVISION=	5
COMMENT=	Signal processing blocks to simulate channel models of GNU Radio

.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_ARGS+=	-DENABLE_GR_CHANNELS=ON

.include	"../../mk/bsd.pkg.mk"
