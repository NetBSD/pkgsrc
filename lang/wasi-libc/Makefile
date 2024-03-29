# $NetBSD: Makefile,v 1.13 2023/11/08 13:19:53 wiz Exp $

GITHUB_PROJECT=	wasi-libc
GITHUB_TAG=	4db5398e65c7dd343315db7e13f3dcae056466ba
DISTNAME=	wasi-libc-0.0.0pre20231007
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=WebAssembly/}

GITHUB_SUBMODULES+=	WebAssembly WASI 59cbe140561db52fc505555e859de884e0ee7f00 wasi/tools/wasi-headers/WASI
EXTRACT_USING=		bsdtar

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/WebAssembly/wasi-libc/
COMMENT=	libc for WebAssembly programs built on top of WASI
LICENSE=	mit AND apache-2.0 # apache-2.0-with-LLVM-exception

# Do not fail tests and compile time error (undefined symbols) in www/firefox.
SSP_SUPPORTED=		no
PKGSRC_USE_STACK_CHECK=	no

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD"
.  if ${OPSYS_VERSION} < 099900
# Use GNU find from findutils for -not option.
TOOLS_PLATFORM.find=	# empty
.  endif
.endif

USE_TOOLS+=	gmake

# Do not crush clang-13
BUILDLINK_TRANSFORM+=	rm:-fcommon

MAKE_FLAGS+=	CC=clang
MAKE_FLAGS+=	AR=${PREFIX}/bin/llvm-ar
MAKE_FLAGS+=	NM=${PREFIX}/bin/llvm-nm
MAKE_FLAGS+=	INSTALL_DIR=${DESTDIR}${PREFIX}/wasi
BUILD_TARGET=	finish

# iconv.h from libiconv get pulled in on SunOS (via clang)
# It conflicts with musl libc so must be removed.
pre-configure:
	rm -f ${BUILDLINK_DIR}/include/iconv.h

ABI=			# 32
CFLAGS=			-O2
CXXFLAGS=		-O2
PKGSRC_COMPILER=	clang
CLANGBASE=		${PREFIX}
BUILDLINK_DEPMETHOD.clang=	build
.include "../../lang/clang/buildlink3.mk"
BUILDLINK_DEPMETHOD.llvm=	build
.include "../../lang/llvm/buildlink3.mk"
.if empty(PKG_BUILD_OPTIONS.llvm:Mllvm-target-webassembly)
PKG_FAIL_REASON+=	"llvm-target-webassembly PKG_OPTION must be enabled in lang/llvm"
.endif
.include "../../mk/bsd.pkg.mk"
