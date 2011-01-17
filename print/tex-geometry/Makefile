# $NetBSD: Makefile,v 1.3 2011/01/17 23:42:37 minskim Exp $

DISTNAME=	geometry
PKGNAME=	tex-${DISTNAME}-5.6
TEXLIVE_REV=	19716

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Flexible and complete interface to document dimensions

CONFLICTS+=	teTeX-texmf<=3.0nb18
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-oberdiek-[0-9]*:../../print/tex-oberdiek

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
