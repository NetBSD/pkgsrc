# $NetBSD: Makefile,v 1.42 2024/08/20 17:46:18 gdt Exp $

PKGNAME=	gnuradio-network-${VERSION}
PKGREVISION=	4
COMMENT=	Network blocks for GNU Radio

.include "../../ham/gnuradio-core/Makefile.common"
.include "../../ham/gnuradio-core/Nocore.mk"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_NETWORK=ON
CMAKE_CONFIGURE_ARGS+=	-DENABLE_GRC=ON

PLIST_MINUS+=	companion

.include "../../mk/bsd.pkg.mk"
