# $NetBSD: Makefile,v 1.6 2005/02/14 15:51:10 minskim Exp $

DISTNAME=	bibtex2html-1.74
PKGREVISION=	1
CATEGORIES=	converters
MASTER_SITES=	http://www.lri.fr/~filliatr/ftp/bibtex2html/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.lri.fr/~filliatr/bibtex2html/
COMMENT=	Collection of tools for translating from BibTeX to HTML

BUILD_DEPENDS=	ocaml>=3.08:../../lang/ocaml
BUILD_DEPENDS+=	hevea-[0-9]*:../../textproc/hevea
DEPENDS+=	teTeX-bin-[0-9]*:../../print/teTeX-bin

NO_BUILDLINK=	yes
GNU_CONFIGURE=	yes
USE_PERL5=	run

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	"Fixing hardcoded paths."
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	aux2bib.1
SUBST_SED.paths=	-e 's,/usr/share,${PREFIX}/share,g'

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

.include "../../mk/bsd.pkg.mk"
