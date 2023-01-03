# $NetBSD: Makefile,v 1.42 2023/01/03 17:37:34 wiz Exp $

PKGNAME=	gnuradio-channels-${VERSION}
PKGREVISION=	2
COMMENT=	Signal processing blocks to simulate channel models of GNU Radio

.include "../../ham/gnuradio-core/Makefile.common"
.include "../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_ARGS+=	-DENABLE_GR_CHANNELS=ON
CMAKE_ARGS+=	-DENABLE_GRC=ON

PLIST_MINUS+=	companion

.include "../../mk/bsd.pkg.mk"
