# $NetBSD: Makefile,v 1.2 2011/02/07 19:11:30 minskim Exp $

DISTNAME=	lastpage
PKGNAME=	tex-${DISTNAME}-1.2g
TEXLIVE_REV=	21261

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Reference last page for Page N of M type footers

CONFLICTS+=	teTeX-texmf<=3.0nb28
DEPENDS+=	tex-latex-bin>=2009nb1:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
