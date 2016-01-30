# $NetBSD: Makefile,v 1.2 2016/01/30 04:05:54 markd Exp $

DISTNAME=	tex-ps
PKGNAME=	tex-${DISTNAME}-2010
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	TeX to PostScript generic macros and add-ons
LICENSE=	public-domain

CONFLICTS=	teTeX-texmf<=3.0nb29
DEPENDS+=	tex-epsf-[0-9]*:../../print/tex-epsf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
