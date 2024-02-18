# $NetBSD: Makefile,v 1.28 2024/02/18 09:47:18 markd Exp $

DISTNAME=	babel
PKGNAME=	tex-${DISTNAME}-24.2
TEXLIVE_REV=	69742

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/babel
COMMENT=	Multilingual support for LaTeX, LuaLaTeX, XeLaTeX, and Plain TeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-carlisle>=2010:../../print/tex-carlisle
DEPENDS+=	tex-graphics>=1.0onb1:../../print/tex-graphics
DEPENDS+=	tex-latex>=2009:../../print/tex-latex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
