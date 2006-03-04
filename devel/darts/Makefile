# $NetBSD: Makefile,v 1.4 2006/03/04 21:29:14 jlam Exp $

DISTNAME=	darts-0.2
CATEGORIES=	devel
MASTER_SITES=	http://chasen.org/~taku/software/darts/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://chasen.org/~taku/software/darts/
COMMENT=	C++ template library that implements Double-Array

USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes

DOCDIR=		${PREFIX}/share/doc/darts
HTMLDOCDIR=	${PREFIX}/share/doc/html/darts
EXAMPLESDIR=	${PREFIX}/share/examples/darts
EXAMPLES=	darts.cpp mkdarts.cpp
DOCS=		AUTHORS ChangeLog README
HTMLDOCS=	darts.css index.html

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCDIR}
.endfor
	${INSTALL_DATA_DIR} ${HTMLDOCDIR}
.for f in ${HTMLDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${HTMLDOCDIR}
.endfor
	${INSTALL_DATA_DIR} ${EXAMPLESDIR}
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${EXAMPLESDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
