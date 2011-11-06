# $NetBSD: Makefile,v 1.2 2011/11/06 08:43:29 minskim Exp $

DISTNAME=	bera
PKGNAME=	tex-${DISTNAME}-2010
PKGREVISION=	1
TEXLIVE_REV=	20031

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Bera fonts

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex

TEX_MAP_FILES+=	bera.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
