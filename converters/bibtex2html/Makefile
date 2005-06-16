# $NetBSD: Makefile,v 1.10 2005/06/16 06:57:43 jlam Exp $

DISTNAME=	bibtex2html-1.75
CATEGORIES=	converters
MASTER_SITES=	http://www.lri.fr/~filliatr/ftp/bibtex2html/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.lri.fr/~filliatr/bibtex2html/
COMMENT=	Collection of tools for translating from BibTeX to HTML

BUILD_DEPENDS+=	hevea-[0-9]*:../../textproc/hevea
DEPENDS+=	teTeX-bin-[0-9]*:../../print/teTeX-bin

GNU_CONFIGURE=	yes
USE_PERL5=	run

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	"Fixing hardcoded paths."
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	aux2bib.1
SUBST_SED.paths=	-e 's,/usr/share,${PREFIX}/share,g'

INSTALLATION_DIRS=	bin man/man1

post-build:
	cd ${WRKSRC}; ${MAKE} doc

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/aux2bib ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bibtex2html ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bib2bib ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/bibtex2html.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/bibtex2html.1 ${PREFIX}/man/man1/bib2bib.1
	${INSTALL_MAN} ${WRKSRC}/aux2bib.1 ${PREFIX}/man/man1/aux2bib.1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/manual.html ${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/manual.ps ${PREFIX}/share/doc/${PKGBASE}

.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
