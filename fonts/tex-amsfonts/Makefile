# $NetBSD: Makefile,v 1.10 2017/09/06 16:27:19 wiz Exp $

DISTNAME=	amsfonts
PKGNAME=	tex-${DISTNAME}-3.04
TEXLIVE_REV=	29208

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/amsfonts
COMMENT=	TeX fonts from the American Mathematical Society
LICENSE=	ofl-v1.1

CONFLICTS+=	tex-cm<2009
CONFLICTS+=	tex-latex-fonts<2009

TEX_MAP_FILES+=		euler.map
TEX_MIXEDMAP_FILES+=	cm.map
TEX_MIXEDMAP_FILES+=	cmextra.map
TEX_MIXEDMAP_FILES+=	cyrillic.map
TEX_MIXEDMAP_FILES+=	latxfont.map
TEX_MIXEDMAP_FILES+=	symbols.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
