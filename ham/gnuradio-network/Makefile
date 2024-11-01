# $NetBSD: Makefile,v 1.45 2024/11/01 00:52:18 wiz Exp $

PKGNAME=	gnuradio-network-${VERSION}
PKGREVISION=	7
COMMENT=	Network blocks for GNU Radio

.include "../../ham/gnuradio-core/Makefile.common"
.include "../../ham/gnuradio-core/Nocore.mk"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_NETWORK=ON
CMAKE_CONFIGURE_ARGS+=	-DENABLE_GRC=ON

PLIST_MINUS+=	companion

.include "../../mk/bsd.pkg.mk"
