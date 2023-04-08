# $NetBSD: Makefile,v 1.25 2023/04/08 05:57:40 markd Exp $

DISTNAME=	babel
PKGNAME=	tex-${DISTNAME}-3.87
TEXLIVE_REV=	66698

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/babel
COMMENT=	Multilingual support for LaTeX, LuaLaTeX, XeLaTeX, and Plain TeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-carlisle>=2010:../../print/tex-carlisle
DEPENDS+=	tex-graphics>=1.0onb1:../../print/tex-graphics
DEPENDS+=	tex-latex>=2009:../../print/tex-latex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
