# $NetBSD: Makefile,v 1.5 2024/01/31 21:04:14 ryoon Exp $

.include "../../cross/mingw-w64-x86_64-gcc-winpthreads/Makefile.common"

PKGNAME=		mingw-w64-i686-${DISTNAME:S/gcc-/gcc-winpthreads-/}
COMMENT=		GNU C Compiler for win32 cross-development

DEPENDS+=		mingw-w64-i686-binutils-[0-9]*:../../cross/mingw-w64-i686-binutils

MINGW_TARGET=		${MINGW_W64_32_TARGET}

.include "../../cross/mingw-w64-i686-winpthreads/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
