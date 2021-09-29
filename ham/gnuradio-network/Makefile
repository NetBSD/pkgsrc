# $NetBSD: Makefile,v 1.8 2021/09/29 19:00:49 adam Exp $

PKGNAME=	gnuradio-network-${VERSION}
PKGREVISION=	2
COMMENT=	Network blocks for GNU Radio

.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_ARGS+=	-DENABLE_GR_NETWORK=ON
CMAKE_ARGS+=	-DENABLE_GRC=ON

PLIST_MINUS+=	companion

.include	"../../mk/bsd.pkg.mk"
