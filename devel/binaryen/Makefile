# $NetBSD: Makefile,v 1.23 2024/08/25 06:18:31 wiz Exp $

VERSION=	116
DISTNAME=	binaryen-${VERSION}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=WebAssembly/}
GITHUB_TAG=	version_${VERSION}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/WebAssembly/binaryen/
COMMENT=	Compiler and toolchain infrastructure library for WebAssembly
LICENSE=	apache-2.0

USE_LANGUAGES=	c c++17

WRKSRC=		${WRKDIR}/binaryen-${GITHUB_TAG}

CMAKE_CONFIGURE_ARGS+=	-DENABLE_WERROR=OFF

PYTHON_FOR_BUILD_ONLY=	yes

.include "options.mk"
.include "../../devel/cmake/build.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
