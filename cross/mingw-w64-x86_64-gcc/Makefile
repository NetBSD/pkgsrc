# $NetBSD: Makefile,v 1.14 2024/01/31 21:04:14 ryoon Exp $

.include "../../cross/mingw-w64-x86_64-gcc/Makefile.common"

PKGNAME=		mingw-w64-x86_64-${DISTNAME}
COMMENT=		GNU C Compiler for win64 cross-development

DEPENDS+=		mingw-w64-x86_64-binutils-[0-9]*:../../cross/mingw-w64-x86_64-binutils

MINGW_TARGET=		${MINGW_W64_64_TARGET}
CONFIGURE_ARGS+=	--disable-dw2-exceptions

.include "../../cross/mingw-w64-x86_64-crt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
