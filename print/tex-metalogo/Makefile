# $NetBSD: Makefile,v 1.1.1.1 2011/01/21 17:25:32 minskim Exp $

DISTNAME=	metalogo
PKGNAME=	tex-${DISTNAME}-0.12
TEXLIVE_REV=	18611

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Extended TeX logo macros

DEPENDS+=	tex-fontspec>=2.1e:../../fonts/tex-fontspec
DEPENDS+=	tex-graphics>=1.0onb1:../../print/tex-graphics
DEPENDS+=	tex-ifxetex>=0.5:../../print/tex-ifxetex
DEPENDS+=	tex-latex-bin>=2010:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
