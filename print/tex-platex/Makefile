# $NetBSD: Makefile,v 1.17 2024/03/24 10:55:46 markd Exp $

DISTNAME=	platex
PKGNAME=	tex-${DISTNAME}-2024
TEXLIVE_REV=	70015

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/platex
COMMENT=	pLaTeX2e and miscellaneous macros for pTeX
LICENSE=	modified-bsd

DEPENDS+=	tex-babel-[0-9]*:../../print/tex-babel
DEPENDS+=	tex-cm-[0-9]*:../../fonts/tex-cm
DEPENDS+=	tex-firstaid-[0-9]*:../../print/tex-firstaid
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-l3backend-[0-9]*:../../devel/tex-l3backend
DEPENDS+=	tex-l3kernel-[0-9]*:../../devel/tex-l3kernel
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-latex-base-dev-[0-9]*:../../print/tex-latex-base-dev
DEPENDS+=	tex-latex-firstaid-dev-[0-9]*:../../print/tex-latex-firstaid-dev
DEPENDS+=	tex-latex-fonts-[0-9]*:../../fonts/tex-latex-fonts
DEPENDS+=	tex-ptex-[0-9]*:../../print/tex-ptex
DEPENDS+=	tex-ptex-fonts-[0-9]*:../../fonts/tex-ptex-fonts
DEPENDS+=	tex-tex-ini-files-[0-9]*:../../print/tex-tex-ini-files
DEPENDS+=	tex-unicode-data-[0-9]*:../../print/tex-unicode-data
DEPENDS+=	tex-uptex-[0-9]*:../../print/tex-uptex

INSTALLATION_DIRS+=	bin

TEX_FORMATS+=	"platex euptex language.dat *platex.ini\\nplatex-dev euptex language.dat *platex.ini\\n"

.include "../../print/texlive/package.mk"

post-install:
	${LN} -sf eptex ${DESTDIR}${PREFIX}/bin/platex
	${LN} -sf euptex ${DESTDIR}${PREFIX}/bin/platex-dev

.include "../../mk/bsd.pkg.mk"
