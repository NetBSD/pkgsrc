# $NetBSD: Makefile,v 1.16 2019/06/21 15:54:14 mef Exp $

PKGNAME=	gnuradio-uhd-${VERSION}
COMMENT=	Uhd-based encoding and decoding algorithms for GNU Radio

.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=False
CMAKE_ARGS+=	-DENABLE_GR_UHD=True
CMAKE_ARGS+=	-DENABLE_PYTHON=True

.if ${OPSYS} != "Darwin"
# XXX dbj -- i'm not sure why this is necessary, but hard coding
# the .so causes problems on Darwin.  I've also set UHD_DIR in
# the uhd buildlink3.mk file, so it finds the buildlink header files.

CMAKE_ARGS+=	-DUHD_LIBRARIES=${PREFIX}/lib/libuhd.so
CMAKE_ARGS+=	-DUHD_INCLUDE_DIRS=${PREFIX}/include/uhd/usrp
.endif

.include	"../../ham/uhd/buildlink3.mk"

.include	"../../mk/bsd.pkg.mk"
