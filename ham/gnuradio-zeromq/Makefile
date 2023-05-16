# $NetBSD: Makefile,v 1.53 2023/05/16 21:20:52 wiz Exp $

PKGNAME=	gnuradio-zeromq-${VERSION}
PKGREVISION=	4
COMMENT=	All of the zeromq blocks, utilities, and examples

.include "../../ham/gnuradio-core/Makefile.common"
.include "../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_ARGS+=	-DENABLE_GR_ZEROMQ=ON
CMAKE_ARGS+=	-DZEROMQ_INCLUDE_DIRS=${PREFIX}/include
CMAKE_ARGS+=	-DENABLE_GRC=ON

PLIST_MINUS+=	companion

.include "../../net/cppzmq/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
