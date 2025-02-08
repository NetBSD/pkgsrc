# $NetBSD: Makefile,v 1.4 2025/02/08 10:11:39 mef Exp $

R_PKGNAME=	sourcetools
R_PKGVER=	0.1.7-1
CATEGORIES=	lang

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Tools for reading, tokenizing and parsing R code
LICENSE=	mit

TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat

TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_LANGUAGES=	c c++

post-configure:
	${ECHO} PKG_CFLAGS=${CFLAGS:Q} >> ${WRKSRC}/src/Makevars
	${ECHO} PKG_CXXFLAGS=${CXXFLAGS:Q} >> ${WRKSRC}/src/Makevars

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
