# $NetBSD: Makefile,v 1.1.1.1 2011/03/06 20:51:17 minskim Exp $

DISTNAME=	bera
PKGNAME=	tex-${DISTNAME}-2010
TEXLIVE_REV=	20031

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Bera fonts

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex

TEX_MAP_FILES+=	bera.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
