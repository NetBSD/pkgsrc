# $NetBSD: Makefile,v 1.6 2019/10/19 13:59:07 adam Exp $

DISTNAME=	libcxx-9.0.0.src
PKGNAME=	${DISTNAME:S/.src//}
CATEGORIES=	lang devel
MASTER_SITES=   http://releases.llvm.org/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libcxx.llvm.org/
COMMENT=	C++ Standard Library
LICENSE=	modified-bsd OR mit

# libcxx requires libcxxabi's cxxabi.h to build, but libcxxabi requires
# libcxx's includes to build, so we have this unholy extra distfiles thing
# in both of them to get them to build against each other without causing
# circular dependencies.  This must be kept in sync with libcxxabi/Makefile.
LIBCXXABI=		${DISTNAME:S/cxx/cxxabi/}
_EXTRA_DIST=		${LIBCXXABI}${EXTRACT_SUFX}

DISTFILES=	${DEFAULT_DISTFILES} ${_EXTRA_DIST}

CONFIGURE_DIRS=	${WRKDIR}/build
CMAKE_ARG_PATH=	${WRKSRC}

USE_LANGUAGES=	c c++
USE_CMAKE=	yes
GCC_REQD+=	4.8
SSP_SUPPORTED=	no

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=	-DCMAKE_C_COMPILER=${CC:Q}
CMAKE_ARGS+=	-DCMAKE_CXX_COMPILER=${CXX:Q}
CMAKE_ARGS+=	-DCMAKE_CXX_LINK_FLAGS=${LDFLAGS:Q}
CMAKE_ARGS+=	-DLIBCXX_CXX_ABI=libcxxabi
CMAKE_ARGS+=	-DLIBCXX_CXX_ABI_INCLUDE_PATHS=${WRKDIR}/${LIBCXXABI}/include
CMAKE_ARGS+=	-DLIBCXX_ENABLE_ABI_LINKER_SCRIPT=OFF

# avoid conflict with stddef.h
CXXFLAGS.NetBSD+=	-D__DEFINED_max_align_t=1

post-extract:
	${MKDIR} ${WRKDIR}/build

.include "../../lang/libcxxabi/buildlink3.mk"
.include "../../lang/llvm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
