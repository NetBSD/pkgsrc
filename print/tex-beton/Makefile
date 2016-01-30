# $NetBSD: Makefile,v 1.2 2016/01/30 03:26:08 markd Exp $

DISTNAME=	beton
PKGNAME=	tex-${DISTNAME}-2010
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Use Concrete fonts
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<3.0nb29
DEPENDS+=	tex-latex-bin>=2010:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
