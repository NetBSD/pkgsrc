# $NetBSD: Makefile,v 1.12 2019/01/27 01:06:00 markd Exp $

DISTNAME=	babel
PKGNAME=	tex-${DISTNAME}-3.27
TEXLIVE_REV=	49149

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/babel
COMMENT=	Multilingual support for Plain TeX or LaTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-carlisle>=2010:../../print/tex-carlisle
DEPENDS+=	tex-graphics>=1.0onb1:../../print/tex-graphics
DEPENDS+=	tex-latex>=2009:../../print/tex-latex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
