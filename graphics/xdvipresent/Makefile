# $NetBSD: Makefile,v 1.23 2012/10/06 14:11:25 asau Exp $
#

DISTNAME=	xdvipresent-0.6p14
PKGNAME=	xdvipresent-0.6.1.14
PKGREVISION=	6
CATEGORIES=	graphics textproc print x11
MASTER_SITES=	http://clip.dia.fi.upm.es/Software/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://clip.dia.fi.upm.es/Software/
COMMENT=	Slide Presentations Using LaTeX/xdvi

DEPENDS+=	latex2html>=2002.2:../../textproc/latex2html
DEPENDS+=	tex-dvips-[0-9]*:../../print/tex-dvips
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex

WRKSRC=		${WRKDIR}/xdvipresent
NO_BUILD=	yes
NO_CONFIGURE=	yes

STYDIR=		${PREFIX}/share/texmf-dist/tex/latex/xdvipresent
EXAMPLES_DIR=	${PREFIX}/share/examples/xdvipresent
HTML_DIR=	${PREFIX}/share/doc/xdvipresent

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${STYDIR}
	${INSTALL_DATA} ${WRKSRC}/*.cls ${DESTDIR}${STYDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${STYDIR}/images
	${INSTALL_DATA} ${WRKSRC}/images/* ${DESTDIR}${STYDIR}/images
	${INSTALL_SCRIPT} ${WRKSRC}/xdvipresent ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/xdvipresent
	${INSTALL_DATA} ${WRKSRC}/example.tex ${DESTDIR}${EXAMPLES_DIR}
	${INSTALL_MAN} ${WRKSRC}/doc/xdvipresent.manl \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/xdvipresent.1
	${INSTALL_DATA_DIR} ${DESTDIR}${HTML_DIR}
	${INSTALL_DATA} ${WRKSRC}/doc/xdvipresent_html/* ${DESTDIR}${HTML_DIR}

.include "../../mk/bsd.pkg.mk"
