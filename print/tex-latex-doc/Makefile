# $NetBSD: Makefile,v 1.10 2016/08/07 09:09:38 markd Exp $

DISTNAME=	latex.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2016.41765
TEXLIVE_REV=	41765

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/latex
COMMENT=	Documentation for tex-latex
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb22

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
