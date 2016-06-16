# $NetBSD: Makefile,v 1.8 2016/06/16 04:06:17 markd Exp $

DISTNAME=	tools
PKGNAME=	tex-${DISTNAME}-2016
TEXLIVE_REV=	40934

MAINTAINER=	minskim@NetBSD.org
COMMENT=	The LaTeX standard tools bundle
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb13
DEPENDS+=	tex-graphics>=1.0onb1:../../print/tex-graphics

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
