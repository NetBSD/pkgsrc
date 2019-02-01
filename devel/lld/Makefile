# $NetBSD: Makefile,v 1.1 2019/02/01 16:30:00 mgorny Exp $

PKGNAME=		lld-7.0.1
DISTNAME=		${PKGNAME}.src
CATEGORIES=		devel
MASTER_SITES=		http://llvm.org/releases/${PKGVERSION_NOREV}/
EXTRACT_SUFX=		.tar.xz
DISTFILES=		${DEFAULT_DISTFILES}

MAINTAINER=		mgorny@NetBSD.org
HOMEPAGE=		http://lld.llvm.org/
COMMENT=		The LLVM Linker
LICENSE=		modified-bsd

USE_LANGUAGES=		c c++11
USE_CMAKE=		yes
GCC_REQD+=		4.8

CONFIGURE_DIRS=		${WRKDIR}/build
CMAKE_ARG_PATH=		${WRKSRC}

CMAKE_ARGS+=		-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=		-DCMAKE_C_COMPILER=${CC:Q}
CMAKE_ARGS+=		-DCMAKE_CXX_COMPILER=${CXX:Q}

PYTHON_FOR_BUILD_ONLY=	yes

post-extract:
	${MKDIR} ${WRKDIR}/build

.include "options.mk"
.include "../../lang/python/tool.mk"
.include "../../lang/llvm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
