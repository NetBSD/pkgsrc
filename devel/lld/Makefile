# $NetBSD: Makefile,v 1.9 2019/10/21 22:07:58 rjs Exp $

DISTNAME=	lld-9.0.0.src
PKGNAME=	${DISTNAME:S/.src//}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://releases.llvm.org/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lld.llvm.org/
COMMENT=	The LLVM Linker
LICENSE=	modified-bsd

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
