# $NetBSD: Makefile,v 1.4 2024/11/28 20:18:44 ryoon Exp $

.include "../../cross/mingw-w64-x86_64-gcc-bootstrap/Makefile.common"

PKGNAME=		mingw-w64-i686-${DISTNAME:S/gcc-/gcc-bootstrap-${CRT_TYPE}-/}
COMMENT=		GNU C Compiler for win32 cross-development (for bootstrap; ${CRT_TYPE})

DEPENDS+=		mingw-w64-i686-binutils-[0-9]*:../../cross/mingw-w64-i686-binutils

CRT_TYPE=		ucrt
MINGW_TARGET=		${MINGW_W64_32_TARGET}

.include "../../cross/mingw-w64-i686-headers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
