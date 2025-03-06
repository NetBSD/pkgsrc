# $NetBSD: Makefile,v 1.12 2025/03/06 13:09:53 gdt Exp $

PKGNAME=	${DISTNAME:S/-/-c++-/}
COMMENT=	Hierarchical Data Format (new generation) - C++ wrappers

WRKSRC=		${WRKDIR}/hdf5-${DISTNAME:S/-/_/}
BUILD_DIRS+=	c++

USE_LANGUAGES=		c c++

CMAKE_CONFIGURE_ARGS+=	-DHDF5_BUILD_CPP_LIB=ON

# BUILD_DIRS (at least for hdf5) is not compatible with ninja.  pkgsrc
# does not support CMAKE_GENERATORS_ACCEPTED=make as a
# package-settable variable to indicate that only make works, so we
# have to abuse CMAKE_GENERATOR (a user-settable variable).  That
# might be set with = in mk.conf, and if so we want to just override
# it, as being more helpful than erroring.  We therefore force reading
# prefs first so that our assignment will prevail.
.include "../../mk/bsd.prefs.mk"
CMAKE_GENERATOR=	make

.include "../../devel/hdf5/Makefile.common"
.include "../../devel/hdf5/buildlink3.mk"
# Since the package is build from source code shared with hdf5,
# same options should be passed:
.include "../../devel/hdf5/options.mk"

.if !empty(PKG_OPTIONS:Mthreads)
PKG_FAIL_REASON=	"Threadsafe HDF5 with C++ interface is unsupported."
.endif

.include "../../mk/bsd.pkg.mk"
