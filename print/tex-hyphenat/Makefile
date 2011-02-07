# $NetBSD: Makefile,v 1.1.1.1 2011/02/07 00:42:11 minskim Exp $

DISTNAME=	hyphenat
PKGNAME=	tex-${DISTNAME}-2.3c
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Disable/enable hypenation in LaTeX

CONFLICT=	teTeX-texmf<=3.0nb29
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
