# $NetBSD: Makefile,v 1.5 2011/11/06 08:43:29 minskim Exp $

DISTNAME=	amsfonts
PKGNAME=	tex-${DISTNAME}-3.0
PKGREVISION=	2
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	TeX fonts from the American Mathematical Society

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
