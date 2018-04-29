# $NetBSD: Makefile,v 1.10 2018/04/29 21:31:46 adam Exp $

PKGNAME=	gnuradio-channels-${VERSION}
PKGREVISION=	4
COMMENT=	Signal processing blocks to simulate channel models of GNU Radio

.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_ARGS+=	-DENABLE_GR_CHANNELS=ON

.include	"../../mk/bsd.pkg.mk"
