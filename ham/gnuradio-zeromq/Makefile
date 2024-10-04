# $NetBSD: Makefile,v 1.68 2024/10/04 03:49:29 ryoon Exp $

PKGNAME=	gnuradio-zeromq-${VERSION}
PKGREVISION=	5
COMMENT=	All of the zeromq blocks, utilities, and examples

.include "../../ham/gnuradio-core/Makefile.common"
.include "../../ham/gnuradio-core/Nocore.mk"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_ZEROMQ=ON
CMAKE_CONFIGURE_ARGS+=	-DZEROMQ_INCLUDE_DIRS=${PREFIX}/include
CMAKE_CONFIGURE_ARGS+=	-DENABLE_GRC=ON

PLIST_MINUS+=	companion

.include "../../net/cppzmq/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
