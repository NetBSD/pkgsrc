# $NetBSD: Makefile,v 1.23 2024/12/26 18:16:57 riastradh Exp $

DISTNAME=	latexmk-486
CATEGORIES=	print
MASTER_SITES=	https://www.cantab.net/users/johncollins/latexmk/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.cantab.net/users/johncollins/latexmk/index.html
COMMENT=	Tool to completely automate generating output from LaTeX documents
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex

USE_TOOLS+=	perl:run
NO_BUILD=	yes
REPLACE_PERL=	latexmk.pl
WRKSRC=		${WRKDIR}/latexmk

CHECK_PORTABILITY_SKIP+=	extra-scripts/myhtlatex2

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/latexmk

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/latexmk.pl ${DESTDIR}${PREFIX}/bin/latexmk
	${INSTALL_MAN} ${WRKSRC}/latexmk.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/latexmk.pdf ${DESTDIR}${PREFIX}/share/doc/latexmk

.include "../../mk/bsd.pkg.mk"
