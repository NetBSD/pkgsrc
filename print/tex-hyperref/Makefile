# $NetBSD: Makefile,v 1.20 2019/12/06 20:21:34 markd Exp $

DISTNAME=	hyperref
PKGNAME=	tex-${DISTNAME}-6.88h
TEXLIVE_REV=	51742

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/hyperref
COMMENT=	Extensive support for hypertext in LaTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics>=1.0onb1:../../print/tex-graphics
DEPENDS+=	tex-ifxetex>=0.6:../../print/tex-ifxetex
DEPENDS+=	tex-latex-bin>=2009nb1:../../print/tex-latex-bin
DEPENDS+=	tex-oberdiek>=2009nb1:../../print/tex-oberdiek
DEPENDS+=	tex-url>=3.2:../../print/tex-url

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
