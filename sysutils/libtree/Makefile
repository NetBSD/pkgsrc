# $NetBSD: Makefile,v 1.2 2022/04/10 08:09:31 nia Exp $

DISTNAME=	libtree-2.0.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=haampie/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/haampie/libtree
COMMENT=	Show library info in a tree form
LICENSE=	mit

USE_LANGUAGES=	c c++17
USE_CMAKE=	yes

GCC_REQD+=	8 # std::filesystem

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release

.include "../../devel/cxxopts/buildlink3.mk"
.include "../../devel/elfio/buildlink3.mk"
.include "../../devel/termcolor/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
