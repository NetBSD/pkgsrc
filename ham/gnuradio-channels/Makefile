# $NetBSD: Makefile,v 1.65 2024/10/04 03:49:27 ryoon Exp $

PKGNAME=	gnuradio-channels-${VERSION}
PKGREVISION=	5
COMMENT=	Signal processing blocks to simulate channel models of GNU Radio

.include "../../ham/gnuradio-core/Makefile.common"
.include "../../ham/gnuradio-core/Nocore.mk"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_CHANNELS=ON
CMAKE_CONFIGURE_ARGS+=	-DENABLE_GRC=ON

PLIST_MINUS+=	companion

.include "../../mk/bsd.pkg.mk"
