# $NetBSD: Makefile,v 1.8 2015/08/09 08:25:48 markd Exp $

DISTNAME=	latex.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2015.37789
TEXLIVE_REV=	37789

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/latex
COMMENT=	Documentation for tex-latex
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb22

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
