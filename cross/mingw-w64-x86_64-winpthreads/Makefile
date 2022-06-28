# $NetBSD: Makefile,v 1.7 2022/06/28 11:31:15 wiz Exp $

PKGREVISION= 1
.include "../../cross/mingw-w64-x86_64-winpthreads/Makefile.common"

PKGNAME=		${DISTNAME:S/mingw-w64-v/mingw-w64-x86_64-winpthreads-/}
COMMENT=		Mingw-w64 winpthreads library for win64 cross-development

BUILD_DEPENDS+=		mingw-w64-x86_64-gcc-bootstrap-[0-9]*:../../cross/mingw-w64-x86_64-gcc-bootstrap

MINGW_TARGET=		${MINGW_W64_64_TARGET}

BUILDLINK_DEPMETHOD.mingw-w64-i686-headers=	build
.include "../../cross/mingw-w64-x86_64-headers/buildlink3.mk"
BUILDLINK_DEPMETHOD.mingw-w64-i686-crt=		build
.include "../../cross/mingw-w64-x86_64-crt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
