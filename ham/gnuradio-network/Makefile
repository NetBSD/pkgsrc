# $NetBSD: Makefile,v 1.13 2022/03/28 10:56:16 tnn Exp $

PKGNAME=	gnuradio-network-${VERSION}
PKGREVISION=	1
COMMENT=	Network blocks for GNU Radio

.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_ARGS+=	-DENABLE_GR_NETWORK=ON
CMAKE_ARGS+=	-DENABLE_GRC=ON

PLIST_MINUS+=	companion

.include	"../../mk/bsd.pkg.mk"
