# $NetBSD: Makefile,v 1.2 2005/03/24 21:12:52 wiz Exp $

DISTNAME=	darts-0.2
CATEGORIES=	devel
MASTER_SITES=	http://chasen.org/~taku/software/darts/src/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://chasen.org/~taku/software/darts/
COMMENT=	C++ template library that implements Double-Array

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
