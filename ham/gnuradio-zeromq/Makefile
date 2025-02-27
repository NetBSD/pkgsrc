# $NetBSD: Makefile,v 1.78 2025/02/27 13:49:55 adam Exp $

PKGNAME=	gnuradio-zeromq-${VERSION}
COMMENT=	All of the zeromq blocks, utilities, and examples

.include "../../ham/gnuradio-core/Makefile.common"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_ZEROMQ=ON
CMAKE_CONFIGURE_ARGS+=	-DZEROMQ_INCLUDE_DIRS=${PREFIX}/include

REPLACE_PYTHON+=	gr-zeromq/examples/python/*.py
REPLACE_PYTHON+=	gr-zeromq/python/zeromq/*.py

.include "../../net/zeromq/buildlink3.mk"
.include "../../net/cppzmq/buildlink3.mk"
.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
