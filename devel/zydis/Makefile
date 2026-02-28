# $NetBSD: Makefile,v 1.2 2026/02/28 07:11:49 wiz Exp $

DISTNAME=	zydis-4.1.1
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=zyantific/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://zydis.re/
COMMENT=	Fast and lightweight x86/x86-64 disassembler
LICENSE=	mit

USE_LANGUAGES=		c

CMAKE_CONFIGURE_ARGS+=	-DZYDIS_BUILD_SHARED_LIB=ON
CMAKE_CONFIGURE_ARGS+=	-DZYDIS_BUILD_EXAMPLES=OFF
CMAKE_CONFIGURE_ARGS+=	-DZYDIS_BUILD_MAN=OFF  # requires ronn-ng
CMAKE_CONFIGURE_ARGS+=	-DZYDIS_BUILD_DOXYGEN=OFF

TEST_TARGET=	test

.include "../../lang/python/tool.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/zycore-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
