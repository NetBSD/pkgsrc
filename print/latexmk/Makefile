# $NetBSD: Makefile,v 1.14 2018/08/22 09:46:14 wiz Exp $

DISTNAME=	latexmk-459
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://users.phys.psu.edu/~collins/software/latexmk/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://users.phys.psu.edu/~collins/software/latexmk/
COMMENT=	Tool to completely automate generating output from LaTeX documents
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex

WRKSRC=		${WRKDIR}/latexmk

USE_TOOLS+=	perl:run

NO_BUILD=	yes

REPLACE_PERL=	latexmk.pl

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/latexmk

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/latexmk.pl ${DESTDIR}${PREFIX}/bin/latexmk
	${INSTALL_MAN} ${WRKSRC}/latexmk.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/latexmk.pdf ${DESTDIR}${PREFIX}/share/doc/latexmk

.include "../../mk/bsd.pkg.mk"
