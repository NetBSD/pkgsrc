# $NetBSD: Makefile,v 1.5 2016/07/09 06:38:51 wiz Exp $

DISTNAME=	latexmk-439
PKGREVISION=	2
CATEGORIES=	print
MASTER_SITES=	http://users.phys.psu.edu/~collins/software/latexmk/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://users.phys.psu.edu/~collins/software/latexmk/
COMMENT=	Tool to completely automate generating output from LaTeX documents

LICENSE=	gnu-gpl-v2

USE_TOOLS+=	perl:run

NO_BUILD=	yes

WRKSRC=		${WRKDIR}

REPLACE_PERL=	latexmk.pl

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/latexmk.pl ${DESTDIR}${PREFIX}/bin/latexmk
	${INSTALL_MAN} ${WRKSRC}/latexmk.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
