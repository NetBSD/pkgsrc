# $NetBSD: Makefile,v 1.5 2019/12/06 20:19:05 markd Exp $

DISTNAME=	cellspace
PKGNAME=	tex-${DISTNAME}-1.8.1
TEXLIVE_REV=	50374

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/cellspace
COMMENT=	Ensure minimal spacing of table cells
LICENSE=	lppl-1.3c

DEPENDS+=	tex-amsmath>=2.13nb1:../../print/tex-amsmath
DEPENDS+=	tex-latex>=2009:../../print/tex-latex
DEPENDS+=	tex-latex-bin>=2009nb1:../../print/tex-latex-bin
DEPENDS+=	tex-tools>=2010:../../print/tex-tools

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
