# $NetBSD: Makefile,v 1.1.1.1 2011/03/06 21:30:24 minskim Exp $

DISTNAME=	bezos
PKGNAME=	tex-${DISTNAME}-2010
TEXLIVE_REV=	20113

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Packages by Javier Bezos

CONFLICTS=	teTeX-texmf<=3.0nb29
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
