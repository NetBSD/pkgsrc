# $NetBSD: Makefile,v 1.6 2021/12/18 10:53:00 fcambus Exp $

VERSION=	104
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
