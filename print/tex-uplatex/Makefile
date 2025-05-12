# $NetBSD: Makefile,v 1.5 2025/05/12 12:27:56 markd Exp $

DISTNAME=	uplatex
PKGNAME=	tex-${DISTNAME}-2025
TEXLIVE_REV=	73848

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/uplatex
COMMENT=	pLaTeX2e and miscellaneous macros for upTeX
LICENSE=	modified-bsd

DEPENDS+=	tex-babel-[0-9]*:../../print/tex-babel
DEPENDS+=	tex-cm-[0-9]*:../../fonts/tex-cm
DEPENDS+=	tex-firstaid-[0-9]*:../../print/tex-firstaid
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-knuth-lib-[0-9]*:../../fonts/tex-knuth-lib
DEPENDS+=	tex-l3backend-[0-9]*:../../devel/tex-l3backend
DEPENDS+=	tex-l3backend-dev-[0-9]*:../../devel/tex-l3backend-dev
DEPENDS+=	tex-l3kernel-[0-9]*:../../devel/tex-l3kernel
DEPENDS+=	tex-l3kernel-dev-[0-9]*:../../devel/tex-l3kernel-dev
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-latex-base-dev-[0-9]*:../../print/tex-latex-base-dev
DEPENDS+=	tex-latex-firstaid-dev-[0-9]*:../../print/tex-latex-firstaid-dev
DEPENDS+=	tex-latex-fonts-[0-9]*:../../fonts/tex-latex-fonts
DEPENDS+=	tex-platex-[0-9]*:../../print/tex-platex
DEPENDS+=	tex-tex-ini-files-[0-9]*:../../print/tex-tex-ini-files
DEPENDS+=	tex-unicode-data-[0-9]*:../../print/tex-unicode-data
DEPENDS+=	tex-uptex-[0-9]*:../../print/tex-uptex
DEPENDS+=	tex-uptex-fonts-[0-9]*:../../fonts/tex-uptex-fonts

INSTALLATION_DIRS+=	bin

TEX_FORMATS+=	"uplatex euptex language.dat *uplatex.ini\\nuplatex-dev euptex language.dat *uplatex.ini\\n"

post-install:
	${LN} -sf euptex ${DESTDIR}${PREFIX}/bin/uplatex
	${LN} -sf euptex ${DESTDIR}${PREFIX}/bin/uplatex-dev

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
