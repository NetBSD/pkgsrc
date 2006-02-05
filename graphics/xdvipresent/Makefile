# $NetBSD: Makefile,v 1.15 2006/02/05 23:09:40 joerg Exp $
#

DISTNAME=	xdvipresent-0.6p14
PKGNAME=	xdvipresent-0.6.1.14
PKGREVISION=	4
CATEGORIES=	graphics textproc print x11
MASTER_SITES=	http://clip.dia.fi.upm.es/Software/

MAINTAINER=	jschauma@NetBSD.org
HOMEPAGE=	http://clip.dia.fi.upm.es/Software/
COMMENT=	Slide Presentations Using LaTeX/xdvi

DEPENDS+=	latex2html>=2002.2:../../textproc/latex2html

WRKSRC=		${WRKDIR}/xdvipresent
NO_BUILD=	yes
NO_CONFIGURE=	yes

STYDIR=		${PKG_LOCALTEXMFPREFIX}/tex/latex/other
EXAMPLES_DIR=	${PREFIX}/share/examples/xdvipresent
HTML_DIR=	${PREFIX}/share/doc/html/xdvipresent

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_DATA_DIR} ${STYDIR}/images
	${INSTALL_DATA} ${WRKSRC}/*.cls ${STYDIR}
	${INSTALL_DATA} ${WRKSRC}/images/* ${STYDIR}/images
	${INSTALL_SCRIPT} ${WRKSRC}/xdvipresent ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/xdvipresent
	${INSTALL_DATA} ${WRKSRC}/example.tex ${EXAMPLES_DIR}
	${INSTALL_MAN} ${WRKSRC}/doc/xdvipresent.manl ${PREFIX}/${PKGMANDIR}/man1/xdvipresent.1
	${INSTALL_DATA_DIR} ${HTML_DIR}
	${INSTALL_DATA} ${WRKSRC}/doc/xdvipresent_html/* ${HTML_DIR}

.include "../../print/teTeX/module.mk"
.include "../../mk/bsd.pkg.mk"
