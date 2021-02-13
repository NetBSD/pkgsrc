# $NetBSD: Makefile,v 1.13 2021/02/13 04:11:52 markd Exp $

DISTNAME=	amscls
PKGNAME=	tex-${DISTNAME}-2020	# actually 2.20.6
TEXLIVE_REV=	55378

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/amscls
COMMENT=	AMS document classes for LaTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath
DEPENDS+=	tex-amsfonts-[0-9]*:../../fonts/tex-amsfonts
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-url>=3.2:../../print/tex-url

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
