# $NetBSD: Makefile,v 1.1.1.1 2011/03/17 18:08:51 minskim Exp $

DISTNAME=	soul
PKGNAME=	tex-${DISTNAME}-2.4
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation for letterspacing, underlining, and more

CONFLICTS=	teTeX-texmf<=3.0nb29
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
