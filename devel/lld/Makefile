# $NetBSD: Makefile,v 1.15 2020/04/18 08:00:49 adam Exp $

.include "../../lang/llvm/version.mk"

DISTNAME=	lld-${LLVM_VERSION}.src
PKGNAME=	${DISTNAME:S/.src//}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://lld.llvm.org/
COMMENT=	The LLVM Linker
LICENSE=	apache-2.0

USE_LANGUAGES=		c c++14
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
.include "../../lang/llvm/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
