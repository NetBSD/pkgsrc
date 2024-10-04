# $NetBSD: Makefile,v 1.43 2024/10/04 03:49:28 ryoon Exp $

PKGNAME=	gnuradio-network-${VERSION}
PKGREVISION=	5
COMMENT=	Network blocks for GNU Radio

.include "../../ham/gnuradio-core/Makefile.common"
.include "../../ham/gnuradio-core/Nocore.mk"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_NETWORK=ON
CMAKE_CONFIGURE_ARGS+=	-DENABLE_GRC=ON

PLIST_MINUS+=	companion

.include "../../mk/bsd.pkg.mk"
