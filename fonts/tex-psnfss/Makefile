# $NetBSD: Makefile,v 1.3 2010/05/10 20:53:38 minskim Exp $

DISTNAME=	psnfss
PKGNAME=	tex-${DISTNAME}-9.2a
PKGREVISION=	1
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Font support for common PostScript fonts

CONFLICTS+=	teTeX-texmf<=3.0nb13
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-symbol-[0-9]*:../../fonts/tex-symbol
DEPENDS+=	tex-zapfding-[0-9]*:../../fonts/tex-zapfding

TEX_MAP_FILES+=	charter.map
TEX_MAP_FILES+=	fpls.map
TEX_MAP_FILES+=	pazo.map
TEX_MAP_FILES+=	utopia.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
