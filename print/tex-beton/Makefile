# $NetBSD: Makefile,v 1.1.1.1 2011/01/22 21:52:49 minskim Exp $

DISTNAME=	beton
PKGNAME=	tex-${DISTNAME}-2010
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Use Concrete fonts

CONFLICTS+=	teTeX-texmf<3.0nb29
DEPENDS+=	tex-latex-bin>=2010:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
