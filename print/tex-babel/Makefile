# $NetBSD: Makefile,v 1.21 2021/06/05 01:46:19 mef Exp $

DISTNAME=	babel
PKGNAME=	tex-${DISTNAME}-3.60
TEXLIVE_REV=	59439

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/babel
COMMENT=	Multilingual support for Plain TeX or LaTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-carlisle>=2010:../../print/tex-carlisle
DEPENDS+=	tex-graphics>=1.0onb1:../../print/tex-graphics
DEPENDS+=	tex-latex>=2009:../../print/tex-latex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
