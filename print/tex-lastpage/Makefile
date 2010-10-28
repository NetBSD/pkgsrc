# $NetBSD: Makefile,v 1.1.1.1 2010/10/28 17:47:06 minskim Exp $

DISTNAME=	lastpage
PKGNAME=	tex-${DISTNAME}-1.2f
TEXLIVE_REV=	19958

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Reference last page for Page N of M type footers

CONFLICTS+=	teTeX-texmf<=3.0nb28
DEPENDS+=	tex-latex-bin>=2009nb1:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
