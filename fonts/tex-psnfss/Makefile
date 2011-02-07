# $NetBSD: Makefile,v 1.6 2011/02/07 01:10:21 minskim Exp $

DISTNAME=	psnfss
PKGNAME=	tex-${DISTNAME}-9.2a
PKGREVISION=	2
TEXLIVE_REV=	20257

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Font support for common PostScript fonts

CONFLICTS+=	teTeX-texmf<=3.0nb13
DEPENDS+=	tex-courier-[0-9]*:../../fonts/tex-courier
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-helvetic-[0-9]*:../../fonts/tex-helvetic
DEPENDS+=	tex-symbol-[0-9]*:../../fonts/tex-symbol
DEPENDS+=	tex-times-[0-9]*:../../fonts/tex-times
DEPENDS+=	tex-zapfding-[0-9]*:../../fonts/tex-zapfding

TEX_MAP_FILES+=	charter.map
TEX_MAP_FILES+=	fpls.map
TEX_MAP_FILES+=	pazo.map
TEX_MAP_FILES+=	utopia.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
