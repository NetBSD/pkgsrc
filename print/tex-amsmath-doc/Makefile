# $NetBSD: Makefile,v 1.9 2017/06/20 20:56:52 markd Exp $

DISTNAME=	amsmath.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2.16a
TEXLIVE_REV=	43813

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/latex-amsmath
COMMENT=	Documentation for tex-amsmath
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb13

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
