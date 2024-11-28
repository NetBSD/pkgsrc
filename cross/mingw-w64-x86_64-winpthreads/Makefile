# $NetBSD: Makefile,v 1.10 2024/11/28 20:31:41 ryoon Exp $

.include "../../cross/mingw-w64-x86_64-winpthreads/Makefile.common"

PKGNAME=		${DISTNAME:S/mingw-w64-v/mingw-w64-x86_64-winpthreads-${CRT_TYPE}-/}
COMMENT=		Mingw-w64 winpthreads library for win64 cross-development (${CRT_TYPE})

TOOL_DEPENDS+=		mingw-w64-x86_64-gcc-bootstrap-ucrt-[0-9]*:../../cross/mingw-w64-x86_64-gcc-bootstrap

CRT_TYPE=		ucrt
MINGW_TARGET=		${MINGW_W64_64_TARGET}

BUILDLINK_DEPMETHOD.mingw-w64-i686-headers-ucrt=	build
.include "../../cross/mingw-w64-x86_64-headers/buildlink3.mk"
BUILDLINK_DEPMETHOD.mingw-w64-i686-crt-ucrt=		build
.include "../../cross/mingw-w64-x86_64-crt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
