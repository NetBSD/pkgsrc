# $NetBSD: Makefile,v 1.1 2026/02/26 22:51:44 alnsn Exp $

DISTNAME=       zycore-c-1.5.1
GITHUB_TAG=     v${PKGVERSION_NOREV}
CATEGORIES=	devel
MASTER_SITES=   ${MASTER_SITE_GITHUB:=zyantific/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://zydis.re
COMMENT=	Internal library for zydis disassembler
LICENSE=	mit

USE_LANGUAGES=	c

CMAKE_CONFIGURE_ARGS+=	-DZYAN_NO_LIBC=OFF
CMAKE_CONFIGURE_ARGS+=	-DZYCORE_BUILD_SHARED_LIB=ON

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
