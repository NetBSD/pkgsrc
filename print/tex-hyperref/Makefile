# $NetBSD: Makefile,v 1.16 2017/09/06 16:49:35 wiz Exp $

DISTNAME=	hyperref
PKGNAME=	tex-${DISTNAME}-6.85a
TEXLIVE_REV=	43547

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
