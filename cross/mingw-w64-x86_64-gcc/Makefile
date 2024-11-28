# $NetBSD: Makefile,v 1.15 2024/11/28 20:24:27 ryoon Exp $

.include "../../cross/mingw-w64-x86_64-gcc/Makefile.common"

PKGNAME=		mingw-w64-x86_64-${DISTNAME:S/gcc-/gcc-${CRT_TYPE}-/}
COMMENT=		GNU C Compiler for win64 cross-development (${CRT_TYPE})

DEPENDS+=		mingw-w64-x86_64-binutils-[0-9]*:../../cross/mingw-w64-x86_64-binutils

CRT_TYPE=		ucrt
MINGW_TARGET=		${MINGW_W64_64_TARGET}
CONFIGURE_ARGS+=	--disable-dw2-exceptions

.include "../../cross/mingw-w64-x86_64-crt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
