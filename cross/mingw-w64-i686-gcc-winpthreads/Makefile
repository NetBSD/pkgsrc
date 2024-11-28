# $NetBSD: Makefile,v 1.6 2024/11/28 20:35:28 ryoon Exp $

.include "../../cross/mingw-w64-x86_64-gcc-winpthreads/Makefile.common"

PKGNAME=		mingw-w64-i686-${DISTNAME:S/gcc-/gcc-winpthreads-${CRT_TYPE}-/}
COMMENT=		GNU C Compiler for win32 cross-development (${CRT_TYPE})

DEPENDS+=		mingw-w64-i686-binutils-[0-9]*:../../cross/mingw-w64-i686-binutils

CRT_TYPE=		ucrt
MINGW_TARGET=		${MINGW_W64_32_TARGET}

.include "../../cross/mingw-w64-i686-winpthreads/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
