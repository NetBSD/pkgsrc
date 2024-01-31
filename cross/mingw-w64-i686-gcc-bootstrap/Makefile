# $NetBSD: Makefile,v 1.3 2024/01/31 21:04:14 ryoon Exp $

.include "../../cross/mingw-w64-x86_64-gcc-bootstrap/Makefile.common"

PKGNAME=		mingw-w64-i686-${DISTNAME:S/gcc-/gcc-bootstrap-/}
COMMENT=		GNU C Compiler for win32 cross-development (for bootstrap)

DEPENDS+=		mingw-w64-i686-binutils-[0-9]*:../../cross/mingw-w64-i686-binutils

MINGW_TARGET=		${MINGW_W64_32_TARGET}

.include "../../cross/mingw-w64-i686-headers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
