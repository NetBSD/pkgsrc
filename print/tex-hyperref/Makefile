# $NetBSD: Makefile,v 1.18 2019/01/28 08:41:14 markd Exp $

DISTNAME=	hyperref
PKGNAME=	tex-${DISTNAME}-6.88e
TEXLIVE_REV=	49299

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/hyperref
COMMENT=	Extensive support for hypertext in LaTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics>=1.0onb1:../../print/tex-graphics
DEPENDS+=	tex-ifxetex>=0.6:../../print/tex-ifxetex
DEPENDS+=	tex-latex-bin>=2009nb1:../../print/tex-latex-bin
DEPENDS+=	tex-oberdiek>=2009nb1:../../print/tex-oberdiek
DEPENDS+=	tex-url>=3.2:../../print/tex-url

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
