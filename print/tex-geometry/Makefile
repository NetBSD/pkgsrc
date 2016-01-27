# $NetBSD: Makefile,v 1.4 2016/01/27 10:32:34 markd Exp $

DISTNAME=	geometry
PKGNAME=	tex-${DISTNAME}-5.6
TEXLIVE_REV=	19716

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Flexible and complete interface to document dimensions
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb18
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-oberdiek-[0-9]*:../../print/tex-oberdiek

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
