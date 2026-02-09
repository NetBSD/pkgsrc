# $NetBSD: Makefile,v 1.1 2026/02/09 16:47:00 ryoon Exp $

DISTNAME=	antlr4-cpp-runtime-4.13.2-source
PKGNAME=	${DISTNAME:S/-source//}
CATEGORIES=	devel
MASTER_SITES=	https://www.antlr.org/download/
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://www.antlr.org/download/
COMMENT=	C++ target for ANTLR 4 parser generator
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}

USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DWITH_DEMO=OFF
CMAKE_CONFIGURE_ARGS+=	-DANTLR_BUILD_CPP_TESTS=OFF

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
