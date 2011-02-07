# $NetBSD: Makefile,v 1.1.1.1 2011/02/07 00:57:58 minskim Exp $

DISTNAME=	ntgclass
PKGNAME=	tex-${DISTNAME}-2010
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	European versions of standard classes

CONFLICTS=	teTeX-texmf<=3.0nb29
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
