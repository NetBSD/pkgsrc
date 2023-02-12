# $NetBSD: Makefile,v 1.16 2023/02/12 22:32:58 fcambus Exp $

VERSION=	112
DISTNAME=	binaryen-${VERSION}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=WebAssembly/}
GITHUB_TAG=	version_${VERSION}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/WebAssembly/binaryen/
COMMENT=	Compiler and toolchain infrastructure library for WebAssembly
LICENSE=	apache-2.0

USE_CMAKE=	yes
USE_LANGUAGES=	c c++17

WRKSRC=		${WRKDIR}/binaryen-${GITHUB_TAG}

CMAKE_ARGS+=	-DENABLE_WERROR=OFF

PYTHON_FOR_BUILD_ONLY=	yes

.include "../../devel/googletest/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
