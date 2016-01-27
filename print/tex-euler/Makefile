# $NetBSD: Makefile,v 1.2 2016/01/27 10:53:21 markd Exp $

DISTNAME=	euler
PKGNAME=	tex-${DISTNAME}-2.5
TEXLIVE_REV=	17261

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Use AMS Euler fonts for math
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<3.0nb29
DEPENDS+=	tex-latex-bin>=2010:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
