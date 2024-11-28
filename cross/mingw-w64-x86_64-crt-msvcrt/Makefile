# $NetBSD: Makefile,v 1.1 2024/11/28 20:04:23 ryoon Exp $

.include "../../cross/mingw-w64-x86_64-crt/Makefile.common"

PKGNAME=		${DISTNAME:S/mingw-w64-v/mingw-w64-x86_64-crt-${CRT_TYPE}-/}
COMMENT=		Mingw-w64 C runtime for win64 cross-development

TOOL_DEPENDS+=		mingw-w64-x86_64-gcc-bootstrap-msvcrt-[0-9]*:../../cross/mingw-w64-x86_64-gcc-bootstrap-msvcrt

CRT_TYPE=		msvcrt
MINGW_TARGET=		${MINGW_W64_64_TARGET}
CONFIGURE_ARGS+=	--disable-lib32
CONFIGURE_ARGS+=	--enable-lib64

.include "../../cross/mingw-w64-x86_64-headers-msvcrt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
