# $NetBSD: Makefile,v 1.6 2016/01/30 03:26:06 markd Exp $

DISTNAME=	amsmath.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2.14
TEXLIVE_REV=	30645

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-amsmath
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb13

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
