# $NetBSD: Makefile,v 1.9 2024/01/31 21:04:14 ryoon Exp $

.include "../../cross/mingw-w64-x86_64-gcc-winpthreads/Makefile.common"

PKGNAME=		mingw-w64-x86_64-${DISTNAME:S/gcc-/gcc-winpthreads-/}
COMMENT=		GNU C Compiler for win64 cross-development

DEPENDS+=		mingw-w64-x86_64-binutils-[0-9]*:../../cross/mingw-w64-x86_64-binutils

MINGW_TARGET=		${MINGW_W64_64_TARGET}

.include "../../cross/mingw-w64-x86_64-winpthreads/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
