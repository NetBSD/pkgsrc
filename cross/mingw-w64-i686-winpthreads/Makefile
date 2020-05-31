# $NetBSD: Makefile,v 1.2 2020/05/31 16:04:39 rillig Exp $

.include "../../cross/mingw-w64-x86_64-winpthreads/Makefile.common"

PKGNAME=		${DISTNAME:S/mingw-w64-v/mingw-w64-i686-winpthreads-/}
COMMENT=		Mingw-w64 winpthreads library  for win32 cross-development

BUILD_DEPENDS+=		mingw-w64-i686-gcc-bootstrap-[0-9]*:../../cross/mingw-w64-i686-gcc-bootstrap

MINGW_TARGET=		${MINGW_W64_32_TARGET}

BUILDLINK_DEPMETHOD.mingw-w64-i686-headers=	build
.include "../../cross/mingw-w64-i686-headers/buildlink3.mk"
BUILDLINK_DEPMETHOD.mingw-w64-i686-crt=		build
.include "../../cross/mingw-w64-i686-crt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
