# $NetBSD: Makefile,v 1.8 2004/04/21 04:51:52 snj Exp $
#

DISTNAME=	xdvipresent-0.6p14
PKGNAME=	xdvipresent-0.6.1.14
PKGREVISION=	2
CATEGORIES=	graphics textproc print x11
MASTER_SITES=	http://clip.dia.fi.upm.es/Software/

MAINTAINER=	jschauma@NetBSD.org
HOMEPAGE=	http://clip.dia.fi.upm.es/Software/
COMMENT=	Slide Presentations Using LaTeX/xdvi

DEPENDS+=	latex2html>=2002.2:../../textproc/latex2html

WRKSRC=		${WRKDIR}/xdvipresent
USE_BUILDLINK3=	yes
NO_BUILD=	yes
NO_CONFIGURE=	yes

STYDIR=		${PREFIX}/share/texmf/tex/latex/other
EXAMPLES_DIR=	${PREFIX}/share/examples/xdvipresent
MAN_DIR=	${PREFIX}/man/
HTML_DIR=	${PREFIX}/share/doc/html/xdvipresent

do-install:
	${INSTALL_DATA_DIR} ${STYDIR}/images
	${INSTALL_DATA} ${WRKSRC}/*.cls ${STYDIR}
	${INSTALL_DATA} ${WRKSRC}/images/* ${STYDIR}/images
	${INSTALL_SCRIPT} ${WRKSRC}/xdvipresent ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/xdvipresent
	${INSTALL_DATA} ${WRKSRC}/example.tex ${EXAMPLES_DIR}
	${INSTALL_MAN} ${WRKSRC}/doc/xdvipresent.manl ${MAN_DIR}/man1/xdvipresent.1
	${INSTALL_DATA_DIR} ${HTML_DIR}
	${INSTALL_DATA} ${WRKSRC}/doc/xdvipresent_html/* ${HTML_DIR}
	${PREFIX}/bin/texconfig rehash

.include "../../print/teTeX-bin/kpathsea.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
