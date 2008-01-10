# $NetBSD: Makefile,v 1.24 2008/01/10 18:15:29 tonio Exp $

DISTNAME=	bibtex2html-1.89
CATEGORIES=	converters
MASTER_SITES=	http://www.lri.fr/~filliatr/ftp/bibtex2html/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.lri.fr/~filliatr/bibtex2html/
COMMENT=	Collection of tools for translating from BibTeX to HTML

BUILD_DEPENDS+=	hevea-[0-9]*:../../textproc/hevea

GNU_CONFIGURE=	yes
USE_TOOLS+=	perl:run
TEX_ACCEPTED=	teTeX3

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing hardcoded paths.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	aux2bib.1
SUBST_SED.paths=	-e 's,/usr/share,${PREFIX}/share,g'

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1
INSTALLATION_DIRS+=	share/doc/${PKGBASE}

post-build:
	set -e; \
	cd ${WRKSRC}; ${MAKE} doc

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/aux2bib ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bibtex2html ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bib2bib ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/bibtex2html.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/bibtex2html.1 ${PREFIX}/${PKGMANDIR}/man1/bib2bib.1
	${INSTALL_MAN} ${WRKSRC}/aux2bib.1 ${PREFIX}/${PKGMANDIR}/man1/aux2bib.1
	${INSTALL_DATA} ${WRKSRC}/manual.html ${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/manual.ps ${PREFIX}/share/doc/${PKGBASE}

.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/tex.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
