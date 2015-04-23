# $NetBSD: Makefile,v 1.3 2015/04/23 12:19:53 markd Exp $

DISTNAME=	mhchem
PKGNAME=	tex-${DISTNAME}-4.00
TEXLIVE_REV=	36738

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Typeset chemical formulae/equations and Risk and Safety phrases
LICENSE=	lppl-1.3c

DEPENDS+=	tex-amsmath>=2.13nb1:../../print/tex-amsmath
DEPENDS=	tex-graphics>=1.0onb1:../../print/tex-graphics
DEPENDS+=	tex-latex>=2009:../../print/tex-latex
DEPENDS+=	tex-oberdiek>=2009nb2:../../print/tex-oberdiek
DEPENDS+=	tex-pgf>=2.00nb1:../../print/tex-pgf
DEPENDS+=	tex-tools>=2010:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
