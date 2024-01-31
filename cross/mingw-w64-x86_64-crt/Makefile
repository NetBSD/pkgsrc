# $NetBSD: Makefile,v 1.15 2024/01/31 21:10:33 ryoon Exp $

.include "../../cross/mingw-w64-x86_64-crt/Makefile.common"

PKGNAME=		${DISTNAME:S/mingw-w64-v/mingw-w64-x86_64-crt-/}
COMMENT=		Mingw-w64 C runtime for win64 cross-development

TOOL_DEPENDS+=		mingw-w64-x86_64-gcc-bootstrap-[0-9]*:../../cross/mingw-w64-x86_64-gcc-bootstrap

MINGW_TARGET=		${MINGW_W64_64_TARGET}
CONFIGURE_ARGS+=	--disable-lib32
CONFIGURE_ARGS+=	--enable-lib64

.include "../../cross/mingw-w64-x86_64-headers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
