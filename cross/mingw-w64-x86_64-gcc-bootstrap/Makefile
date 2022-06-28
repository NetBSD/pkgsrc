# $NetBSD: Makefile,v 1.4 2022/06/28 11:31:15 wiz Exp $

PKGREVISION= 1
.include "../../cross/mingw-w64-x86_64-gcc-bootstrap/Makefile.common"

PKGNAME=		mingw-w64-x86_64-${DISTNAME:S/gcc-/gcc-bootstrap-/}
COMMENT=		GNU C Compiler for win64 cross-development (for bootstrap)

DEPENDS+=		mingw-w64-x86_64-binutils-[0-9]*:../../cross/mingw-w64-x86_64-binutils

MINGW_TARGET=		${MINGW_W64_64_TARGET}

.include "../../cross/mingw-w64-x86_64-headers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
