# $NetBSD: Makefile,v 1.2 2014/10/28 16:59:33 mef Exp $

PKGNAME=	gnuradio-doxygen-${VERSION}
COMMENT=	Doxygen documentation of GNU Radio

.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

BUILD_DEPENDS+=	doxygen-[0-9]*:../../devel/doxygen
BUILD_DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx

CMAKE_ARGS+=	-DENABLE_DEFAULT=False
CMAKE_ARGS+=	-DENABLE_DOXYGEN=ON
CMAKE_ARGS+=	-DENABLE_SPHINX=ON

MAKE_JOBS_SAFE=	no

.include	"../../mk/bsd.pkg.mk"
