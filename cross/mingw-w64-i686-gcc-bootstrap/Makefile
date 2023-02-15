# $NetBSD: Makefile,v 1.2 2023/02/15 20:49:11 ryoon Exp $

.include "../../cross/mingw-w64-x86_64-gcc-bootstrap/Makefile.common"

PKGNAME=		mingw-w64-i686-${DISTNAME:S/gcc-/gcc-bootstrap-/}
PKGREVISION=		1
COMMENT=		GNU C Compiler for win32 cross-development (for bootstrap)

DEPENDS+=		mingw-w64-i686-binutils-[0-9]*:../../cross/mingw-w64-i686-binutils

MINGW_TARGET=		${MINGW_W64_32_TARGET}

.include "../../cross/mingw-w64-i686-headers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
