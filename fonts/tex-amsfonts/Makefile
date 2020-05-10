# $NetBSD: Makefile,v 1.13 2020/05/10 04:31:36 markd Exp $

DISTNAME=	amsfonts
PKGNAME=	tex-${DISTNAME}-3.04
PKGREVISION=	1
TEXLIVE_REV=	29208

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/amsfonts
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

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
