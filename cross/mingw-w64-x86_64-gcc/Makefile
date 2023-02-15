# $NetBSD: Makefile,v 1.12 2023/02/15 20:49:11 ryoon Exp $

.include "../../cross/mingw-w64-x86_64-gcc/Makefile.common"

PKGNAME=		mingw-w64-x86_64-${DISTNAME}
PKGREVISION=		1
COMMENT=		GNU C Compiler for win64 cross-development

DEPENDS+=		mingw-w64-x86_64-binutils-[0-9]*:../../cross/mingw-w64-x86_64-binutils

MINGW_TARGET=		${MINGW_W64_64_TARGET}

.include "../../cross/mingw-w64-x86_64-crt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
