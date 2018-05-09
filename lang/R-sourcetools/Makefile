# $NetBSD: Makefile,v 1.1 2018/05/09 00:32:50 minskim Exp $

DISTNAME=	sourcetools_0.1.7
CATEGORIES=	lang

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Tools for Reading, Tokenizing and Parsing R Code
LICENSE=	mit

USE_LANGUAGES=	c c++

BUILDLINK_API_DEPENDS.R+=	R>=3.0.2
.include "../../math/R/Makefile.extension"

post-configure:
	${ECHO} PKG_CFLAGS=${CFLAGS:Q} >> ${WRKSRC}/src/Makevars
	${ECHO} PKG_CXXFLAGS=${CXXFLAGS:Q} >> ${WRKSRC}/src/Makevars

.include "../../mk/bsd.pkg.mk"
