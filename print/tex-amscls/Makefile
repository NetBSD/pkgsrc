# $NetBSD: Makefile,v 1.11 2019/12/06 20:18:47 markd Exp $

DISTNAME=	amscls
PKGNAME=	tex-${DISTNAME}-2018	# actually 2.20.4
TEXLIVE_REV=	46099

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/amscls
COMMENT=	AMS document classes for LaTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath
DEPENDS+=	tex-amsfonts-[0-9]*:../../fonts/tex-amsfonts
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-url>=3.2:../../print/tex-url

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
