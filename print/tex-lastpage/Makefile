# $NetBSD: Makefile,v 1.3 2015/04/23 11:52:29 markd Exp $

DISTNAME=	lastpage
PKGNAME=	tex-${DISTNAME}-1.2m
TEXLIVE_REV=	36680

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Reference last page for Page N of M type footers
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb28
DEPENDS+=	tex-latex-bin>=2009nb1:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
