# $NetBSD: Makefile,v 1.16 2019/08/22 12:23:21 ryoon Exp $

PKGNAME=	gnuradio-channels-${VERSION}
PKGREVISION=	2
COMMENT=	Signal processing blocks to simulate channel models of GNU Radio

.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_ARGS+=	-DENABLE_GR_CHANNELS=ON

.include	"../../mk/bsd.pkg.mk"
