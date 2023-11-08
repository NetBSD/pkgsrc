# $NetBSD: Makefile,v 1.58 2023/11/08 13:19:44 wiz Exp $

PKGNAME=	gnuradio-zeromq-${VERSION}
PKGREVISION=	1
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
