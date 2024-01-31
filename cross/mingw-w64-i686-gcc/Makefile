# $NetBSD: Makefile,v 1.10 2024/01/31 21:04:13 ryoon Exp $

.include "../../cross/mingw-w64-x86_64-gcc/Makefile.common"

PKGNAME=		mingw-w64-i686-${DISTNAME}
COMMENT=		GNU C Compiler for win32 cross-development

DEPENDS+=		mingw-w64-i686-binutils-[0-9]*:../../cross/mingw-w64-i686-binutils

MINGW_TARGET=		${MINGW_W64_32_TARGET}
CONFIGURE_ARGS+=	--enable-dw2-exceptions
CONFIGURE_ARGS+=	--disable-sjlj-exceptions

.include "../../cross/mingw-w64-i686-crt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
