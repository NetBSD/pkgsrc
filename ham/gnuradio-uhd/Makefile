# $NetBSD: Makefile,v 1.77 2025/02/27 13:49:54 adam Exp $

PKGNAME=	gnuradio-uhd-${VERSION}
COMMENT=	Uhd-based encoding and decoding algorithms for GNU Radio

.include "../../ham/gnuradio-core/Makefile.common"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_UHD=ON

#.if ${OPSYS} != "Darwin"
# XXX dbj -- i'm not sure why this is necessary, but hard coding
# the .so causes problems on Darwin.  I've also set UHD_DIR in
# the uhd buildlink3.mk file, so it finds the buildlink header files.
#CMAKE_CONFIGURE_ARGS+=	-DUHD_LIBRARIES=${PREFIX}/lib/libuhd.so
#CMAKE_CONFIGURE_ARGS+=	-DUHD_INCLUDE_DIRS=${PREFIX}/include/uhd/usrp
#.endif

REPLACE_PYTHON+=	gr-uhd/apps/*.py
REPLACE_PYTHON+=	gr-uhd/examples/python/*.py
REPLACE_PYTHON+=	gr-uhd/python/uhd/*.py

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../ham/uhd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
