# $NetBSD: Makefile,v 1.3 2010/01/29 08:21:20 minskim Exp $
# TeX Live Revision 15878

DISTNAME=	amsfonts
PKGNAME=	tex-${DISTNAME}-3.0

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
