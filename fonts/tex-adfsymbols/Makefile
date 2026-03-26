# $NetBSD: Makefile,v 1.8 2026/03/26 08:42:06 markd Exp $

DISTNAME=	adfsymbols
PKGNAME=	tex-${DISTNAME}-1.5
TEXLIVE_REV=	78315

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/adfsymbols
COMMENT=	SymbolsADF with TeX/LaTeX support
LICENSE=	lppl-1.3c AND gnu-gpl-v2

DEPENDS+=	tex-fixtounicode-[0-9]*:../../fonts/tex-fixtounicode

TEX_MAP_FILES+=	adfsymbols.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
