# $NetBSD: Makefile,v 1.7 2015/06/14 12:50:06 markd Exp $

DISTNAME=	tools
PKGNAME=	tex-${DISTNAME}-2015
TEXLIVE_REV=	36834

MAINTAINER=	minskim@NetBSD.org
COMMENT=	The LaTeX standard tools bundle
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb13
DEPENDS+=	tex-graphics>=1.0onb1:../../print/tex-graphics

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
