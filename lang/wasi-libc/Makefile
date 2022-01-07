# $NetBSD: Makefile,v 1.4 2022/01/07 13:32:48 tnn Exp $

GITHUB_PROJECT=	wasi-libc
GITHUB_TAG=	ad5133410f66b93a2381db5b542aad5e0964db96
DISTNAME=	wasi-libc-0.0.0pre20210923
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=WebAssembly/}

GITHUB_SUBMODULES+=	WebAssembly WASI 3423c9c83c7219095d6e67faaf62598ad370064c wasi/tools/wasi-headers/WASI

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

MAKE_FLAGS+=	WASM_CC=clang
MAKE_FLAGS+=	WASM_AR=${PREFIX}/bin/llvm-ar
MAKE_FLAGS+=	WASM_NM=${PREFIX}/bin/llvm-nm
MAKE_FLAGS+=	INSTALL_DIR=${DESTDIR}${PREFIX}/wasi
BUILD_TARGET=	finish

ABI=			32
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
