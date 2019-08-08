# $NetBSD: Makefile,v 1.3 2019/08/08 19:53:43 brook Exp $

R_PKGNAME=	sourcetools
R_PKGVER=	0.1.7
CATEGORIES=	lang

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Tools for reading, tokenizing and parsing R code
LICENSE=	mit

USE_LANGUAGES=	c c++

post-configure:
	${ECHO} PKG_CFLAGS=${CFLAGS:Q} >> ${WRKSRC}/src/Makevars
	${ECHO} PKG_CXXFLAGS=${CXXFLAGS:Q} >> ${WRKSRC}/src/Makevars

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
