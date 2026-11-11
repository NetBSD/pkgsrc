# $NetBSD: Makefile,v 1.15 2026/11/11 11:52:34 wiz Exp $

PKGNAME=	${DISTNAME:S/-/-c++-/}
PKGREVISION=	1
COMMENT=	Hierarchical Data Format (new generation) - C++ wrappers

WRKSRC=		${WRKDIR}/hdf5-${DISTNAME:S/-/_/}
BUILD_DIRS+=	c++

USE_LANGUAGES=		c c++

CMAKE_CONFIGURE_ARGS+=	-DHDF5_BUILD_CPP_LIB=ON

# BUILD_DIRS is not compatible with ninja.
CMAKE_GENERATORS_INCOMPATIBLE=	ninja

.include "../../devel/hdf5/Makefile.common"
.include "../../devel/hdf5/buildlink3.mk"
# Since the package is build from source code shared with hdf5,
# same options should be passed:
.include "../../devel/hdf5/options.mk"

.if !empty(PKG_OPTIONS:Mthreads)
PKG_FAIL_REASON=	"Threadsafe HDF5 with C++ interface is unsupported."
.endif

SUBST_FILES.unwrap+=	${DESTDIR}${PREFIX}/bin/h5c++

.include "../../mk/bsd.pkg.mk"
