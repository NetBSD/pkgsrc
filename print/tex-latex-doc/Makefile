# $NetBSD: Makefile,v 1.6 2015/04/23 11:57:55 markd Exp $

DISTNAME=	latex.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2014
TEXLIVE_REV=	35577

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-latex
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb22

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
