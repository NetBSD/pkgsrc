# $NetBSD: Makefile,v 1.2 2010/05/26 03:56:11 minskim Exp $

DISTNAME=	subfig
PKGNAME=	tex-${DISTNAME}-1.3
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Figures broken into subfigures

CONFLICTS+=	teTeX-texmf<=3.0nb19
DEPENDS+=	tex-caption-[0-9]*:../../print/tex-caption
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
