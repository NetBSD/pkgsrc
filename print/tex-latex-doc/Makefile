# $NetBSD: Makefile,v 1.9 2016/06/16 04:06:11 markd Exp $

DISTNAME=	latex.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2016
TEXLIVE_REV=	40218

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/latex
COMMENT=	Documentation for tex-latex
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb22

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
