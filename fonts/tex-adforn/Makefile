# $NetBSD: Makefile,v 1.8 2026/03/26 08:38:53 markd Exp $

DISTNAME=	adforn
PKGNAME=	tex-${DISTNAME}-1.4
TEXLIVE_REV=	78315

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/adforn
COMMENT=	OrnementsADF font with TeX/LaTeX support
LICENSE=	lppl-1.3c AND gnu-gpl-v2

DEPENDS+=	tex-fixtounicode-[0-9]*:../../fonts/tex-fixtounicode

TEX_MAP_FILES+=	adforn.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
