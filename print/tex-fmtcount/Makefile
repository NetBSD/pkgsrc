# $NetBSD: Makefile,v 1.6 2018/05/06 02:57:21 markd Exp $

DISTNAME=	fmtcount
PKGNAME=	tex-${DISTNAME}-3.05
TEXLIVE_REV=	46159

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/fmtcount
COMMENT=	Display the value of a LaTeX counter in a variety of formats
LICENSE=	lppl-1.3c

DEPENDS+=	tex-amsmath>=2.13:../../print/tex-amsmath
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-latex-bin>=2010:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
