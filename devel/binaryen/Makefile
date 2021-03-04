# $NetBSD: Makefile,v 1.2 2021/03/04 02:13:13 fcambus Exp $

VERSION=	100
DISTNAME=	binaryen-${VERSION}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=WebAssembly/}
GITHUB_TAG=	version_${VERSION}

MAINTAINER=	fcambus@NetBSD.org
HOMEPAGE=	https://github.com/WebAssembly/binaryen/
COMMENT=	Compiler and toolchain infrastructure library for WebAssembly
LICENSE=	apache-2.0

USE_CMAKE=	yes
USE_LANGUAGES=	c c++14

WRKSRC=		${WRKDIR}/binaryen-${GITHUB_TAG}

CMAKE_ARGS+=	-DENABLE_WERROR=OFF

PYTHON_FOR_BUILD_ONLY=	yes

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
