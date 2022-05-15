# $NetBSD: Makefile,v 1.23 2022/05/15 04:13:43 markd Exp $

DISTNAME=	babel
PKGNAME=	tex-${DISTNAME}-3.74
TEXLIVE_REV=	63189

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/babel
COMMENT=	Multilingual support for LaTeX, LuaLaTeX, XeLaTeX, and Plain TeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-carlisle>=2010:../../print/tex-carlisle
DEPENDS+=	tex-graphics>=1.0onb1:../../print/tex-graphics
DEPENDS+=	tex-latex>=2009:../../print/tex-latex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
