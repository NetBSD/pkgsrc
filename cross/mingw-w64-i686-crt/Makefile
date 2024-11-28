# $NetBSD: Makefile,v 1.12 2024/11/28 20:02:52 ryoon Exp $

.include "../../cross/mingw-w64-x86_64-crt/Makefile.common"

PKGNAME=		${DISTNAME:S/mingw-w64-v/mingw-w64-i686-crt-${CRT_TYPE}-/}
COMMENT=		Mingw-w64 C runtime for win32 cross-development (${CRT_TYPE})

TOOL_DEPENDS+=		mingw-w64-i686-gcc-bootstrap-ucrt-[0-9]*:../../cross/mingw-w64-i686-gcc-bootstrap

CRT_TYPE=		ucrt
MINGW_TARGET=		${MINGW_W64_32_TARGET}
CONFIGURE_ARGS+=	--enable-lib32
CONFIGURE_ARGS+=	--disable-lib64

.include "../../cross/mingw-w64-i686-headers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
