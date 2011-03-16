# $NetBSD: Makefile,v 1.1.1.1 2011/03/16 17:58:42 minskim Exp $

DISTNAME=	tex-ps
PKGNAME=	tex-${DISTNAME}-2010
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	TeX to PostScript generic macros and add-ons

CONFLICTS=	teTeX-texmf<=3.0nb29
DEPENDS+=	tex-epsf-[0-9]*:../../print/tex-epsf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
