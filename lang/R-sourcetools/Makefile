# $NetBSD: Makefile,v 1.2 2019/07/31 16:17:04 brook Exp $

CATEGORIES=	lang R

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Tools for reading, tokenizing and parsing R code
LICENSE=	mit

R_PKGNAME=	sourcetools
R_PKGVER=	0.1.7

USE_LANGUAGES=	c c++

post-configure:
	${ECHO} PKG_CFLAGS=${CFLAGS:Q} >> ${WRKSRC}/src/Makevars
	${ECHO} PKG_CXXFLAGS=${CXXFLAGS:Q} >> ${WRKSRC}/src/Makevars

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
