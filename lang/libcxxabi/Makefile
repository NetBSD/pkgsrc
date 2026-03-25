# $NetBSD: Makefile,v 1.24 2026/03/25 22:56:26 wiz Exp $

.include "../../lang/llvm/version.mk"

EXTRACT_ELEMENTS+=	${DISTNAME}/libc
EXTRACT_ELEMENTS+=	${DISTNAME}/libcxx

PKGNAME=	libcxxabi-${LLVM_VERSION}

CATEGORIES=	lang devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://libcxxabi.llvm.org/
COMMENT=	C++ Standard Library
LICENSE=	apache-2.0

USE_CXX_FEATURES=	c++20
USE_LANGUAGES=		c c++
SSP_SUPPORTED=		no
GCC_REQD+=		14 # must be in sync with libcxx

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
# "LIBCXXABI_USE_LLVM_UNWINDER is set to ON, but libunwind is not specified in LLVM_ENABLE_RUNTIMES."
CMAKE_CONFIGURE_ARGS+=	-DLIBCXXABI_USE_LLVM_UNWINDER=OFF

# avoid conflict with stddef.h
CXXFLAGS.NetBSD+=	-D__DEFINED_max_align_t=1

.include "../../mk/compiler.mk"

.if ${CC_VERSION:Mgcc-[0-9].*} || ${CC_VERSION:Mgcc-10.*}
# Avoid GCC < 11 error https://github.com/llvm/llvm-project/issues/54018
CXXFLAGS+=	-std=c++17 -D_LIBCPP_STD_VER=17
.endif

# IMPORTANT: copy __assertion_handler and __config_site from partial build of libcxx.
pre-configure:
	${CP} ${FILESDIR}/__assertion_handler ${FILESDIR}/__config_site \
		${WRKSRC}/../libcxx/include/

.include "../../devel/cmake/build.mk"
.include "../../lang/libunwind/buildlink3.mk"
.include "../../lang/llvm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
