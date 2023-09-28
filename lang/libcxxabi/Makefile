# $NetBSD: Makefile,v 1.17 2023/09/28 21:32:13 joerg Exp $

.include "../../lang/llvm/version.mk"

DISTNAME=	libcxxabi-${LLVM_VERSION}.src
PKGNAME=	${DISTNAME:S/.src//}
PKGREVISION=	1
CATEGORIES=	lang devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://libcxxabi.llvm.org/
COMMENT=	C++ Standard Library
LICENSE=	apache-2.0

# libcxx requires libcxxabi's cxxabi.h to build, but libcxxabi requires
# libcxx's includes to build, so we have this unholy extra distfiles thing
# in both of them to get them to build against each other without causing
# circular dependencies.  This must be kept in sync with libcxxabi/Makefile.
LIBCXX=		libcxx-${LLVM_VERSION}.src
EXTRA_DIST+=	${LIBCXX}${EXTRACT_SUFX}

SITES.${LIBCXX}${EXTRACT_SUFX}=	\
	${MASTER_SITES:=${GITHUB_PROJECT}/releases/download/${GITHUB_RELEASE}/}

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	${WRKSRC}

USE_LANGUAGES=	c c++17
USE_CMAKE=	yes
SSP_SUPPORTED=	no
GCC_REQD+=	10	# must be in sync with libcxx

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release

# avoid conflict with stddef.h
CXXFLAGS.NetBSD+=	-D__DEFINED_max_align_t=1

.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:Mgcc-[0-9].*) || !empty(CC_VERSION:Mgcc-10.*)
# Avoid GCC < 11 error https://github.com/llvm/llvm-project/issues/54018
CXXFLAGS+=		-std=c++17 -D_LIBCPP_STD_VER=17
.endif

post-extract:
	${MKDIR} ${WRKSRC}/build
	${LN} -f -s ${WRKDIR}/${LIBCXX} ${WRKDIR}/libcxx
# TODO: not sure what should create this and with which contents
	${TOUCH} ${WRKDIR}/${LIBCXX}/include/__config_site

.include "../../lang/libunwind/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
