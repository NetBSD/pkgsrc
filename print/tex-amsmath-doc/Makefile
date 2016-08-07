# $NetBSD: Makefile,v 1.8 2016/08/07 09:09:37 markd Exp $

DISTNAME=	amsmath.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2.15d
TEXLIVE_REV=	41561

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/latex-amsmath
COMMENT=	Documentation for tex-amsmath
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb13

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
