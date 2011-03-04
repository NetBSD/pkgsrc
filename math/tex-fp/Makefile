# $NetBSD: Makefile,v 1.1.1.1 2011/03/04 19:05:21 minskim Exp $

DISTNAME=	fp
PKGNAME=	tex-${DISTNAME}-2010
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Fixed point arithmetic

CONFLICTS=	teTeX-texmf<=3.0nb29
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
