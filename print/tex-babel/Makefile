# $NetBSD: Makefile,v 1.26 2023/06/11 05:15:17 markd Exp $

DISTNAME=	babel
PKGNAME=	tex-${DISTNAME}-3.89
TEXLIVE_REV=	67073

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/babel
COMMENT=	Multilingual support for LaTeX, LuaLaTeX, XeLaTeX, and Plain TeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-carlisle>=2010:../../print/tex-carlisle
DEPENDS+=	tex-graphics>=1.0onb1:../../print/tex-graphics
DEPENDS+=	tex-latex>=2009:../../print/tex-latex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
