# $NetBSD: Makefile,v 1.9 2021/12/08 16:05:09 adam Exp $

PKGNAME=	gnuradio-network-${VERSION}
PKGREVISION=	3
COMMENT=	Network blocks for GNU Radio

.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_ARGS+=	-DENABLE_GR_NETWORK=ON
CMAKE_ARGS+=	-DENABLE_GRC=ON

PLIST_MINUS+=	companion

.include	"../../mk/bsd.pkg.mk"
