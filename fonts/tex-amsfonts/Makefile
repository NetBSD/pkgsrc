# $NetBSD: Makefile,v 1.7 2013/04/28 21:07:44 ryoon Exp $

DISTNAME=	amsfonts
PKGNAME=	tex-${DISTNAME}-3.03
TEXLIVE_REV=	26315

MAINTAINER=	minskim@NetBSD.org
COMMENT=	TeX fonts from the American Mathematical Society
LICENSE=	ofl-v1.1

CONFLICTS+=	teTeX-texmf<=3.0nb13
CONFLICTS+=	tex-cm<2009
CONFLICTS+=	tex-latex-fonts<2009
CONFLICTS+=	tex-misc<2009

TEX_MAP_FILES+=		euler.map
TEX_MIXEDMAP_FILES+=	cm.map
TEX_MIXEDMAP_FILES+=	cmextra.map
TEX_MIXEDMAP_FILES+=	cyrillic.map
TEX_MIXEDMAP_FILES+=	latxfont.map
TEX_MIXEDMAP_FILES+=	symbols.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
