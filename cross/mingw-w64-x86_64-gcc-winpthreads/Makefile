# $NetBSD: Makefile,v 1.10 2024/11/28 20:34:15 ryoon Exp $

.include "../../cross/mingw-w64-x86_64-gcc-winpthreads/Makefile.common"

PKGNAME=		mingw-w64-x86_64-${DISTNAME:S/gcc-/gcc-winpthreads-${CRT_TYPE}-/}
COMMENT=		GNU C Compiler for win64 cross-development (${CRT_TYPE})

DEPENDS+=		mingw-w64-x86_64-binutils-[0-9]*:../../cross/mingw-w64-x86_64-binutils

CRT_TYPE=		ucrt
MINGW_TARGET=		${MINGW_W64_64_TARGET}

.include "../../cross/mingw-w64-x86_64-winpthreads/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
