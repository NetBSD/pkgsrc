# $NetBSD: Makefile,v 1.6 2019/10/19 13:59:07 adam Exp $

DISTNAME=	libcxxabi-9.0.0.src
PKGNAME=	${DISTNAME:S/.src//}
CATEGORIES=	lang devel
MASTER_SITES=	http://releases.llvm.org/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libcxxabi.llvm.org/
COMMENT=	C++ Standard Library
LICENSE=	modified-bsd OR mit

# libcxx requires libcxxabi's cxxabi.h to build, but libcxxabi requires
# libcxx's includes to build, so we have this unholy extra distfiles thing
# in both of them to get them to build against each other without causing
# circular dependencies.  This must be kept in sync with libcxxabi/Makefile.
LIBCXX=			${DISTNAME:S/cxxabi/cxx/}
_EXTRA_DIST=		${LIBCXX}${EXTRACT_SUFX}
#SITES.${_EXTRA_DIST}=	${MASTER_SITES:=${GITHUB_PROJECT}/releases/download/${GITHUB_RELEASE}/}

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
CMAKE_ARGS+=	-DLIBCXXABI_LIBCXX_INCLUDES=${WRKDIR}/${LIBCXX}/include
CMAKE_ARGS+=	-DLIBCXXABI_USE_LLVM_UNWINDER=YES

# avoid conflict with stddef.h
CXXFLAGS.NetBSD+=	-D__DEFINED_max_align_t=1

post-extract:
	${MKDIR} ${WRKDIR}/build

.include "../../lang/libunwind/buildlink3.mk"
.include "../../lang/llvm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
