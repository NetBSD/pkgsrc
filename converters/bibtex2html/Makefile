# $NetBSD: Makefile,v 1.5 2005/02/14 15:40:19 minskim Exp $

DISTNAME=	bibtex2html-1.74
CATEGORIES=	converters
MASTER_SITES=	http://www.lri.fr/~filliatr/ftp/bibtex2html/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.lri.fr/~filliatr/bibtex2html/
COMMENT=	Collection of tools for translating from BibTeX to HTML

BUILD_DEPENDS=	ocaml>=3.08:../../lang/ocaml
DEPENDS+=	teTeX-bin-[0-9]*:../../print/teTeX-bin

NO_BUILDLINK=	yes
GNU_CONFIGURE=	yes
USE_PERL5=	run

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/aux2bib ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bibtex2html ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bib2bib ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/bibtex2html.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/bibtex2html.1 ${PREFIX}/man/man1/bib2bib.1
	${INSTALL_MAN} ${WRKSRC}/aux2bib.1 ${PREFIX}/man/man1/aux2bib.1

.include "../../mk/bsd.pkg.mk"
