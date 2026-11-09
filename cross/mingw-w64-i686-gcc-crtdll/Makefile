# $NetBSD: Makefile,v 1.1 2026/11/09 23:05:13 js Exp $

.include "../../cross/mingw-w64-x86_64-gcc/Makefile.common"

PKGNAME=		mingw-w64-i686-${DISTNAME:S/gcc-/gcc-${CRT_TYPE}-/}
COMMENT=		GNU C Compiler for win32 cross-development

DEPENDS+=		mingw-w64-i686-binutils-[0-9]*:../../cross/mingw-w64-i686-binutils

CRT_TYPE=		crtdll
MINGW_TARGET=		${MINGW_W64_32_TARGET}
# No C++, as it requires the _w* functions that are not in crtdll.
MINGW_LANGUAGES=	c,lto,objc,fortran
CONFIGURE_ARGS+=	--enable-dw2-exceptions
CONFIGURE_ARGS+=	--disable-sjlj-exceptions

.include "../../cross/mingw-w64-i686-crt-crtdll/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
