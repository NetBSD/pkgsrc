# $NetBSD: Makefile,v 1.21 2022/04/15 03:45:24 markd Exp $

DISTNAME=	latex
PKGNAME=	tex-${DISTNAME}-20211115.1
TEXLIVE_REV=	61232

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/latex
COMMENT=	TeX macro package that defines LaTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-fonts-[0-9]*:../../fonts/tex-latex-fonts
DEPENDS+=	tex-latexconfig>=2011:../../print/tex-latexconfig
DEPENDS+=	tex-luatex-[0-9]*:../../print/tex-luatex
DEPENDS+=	tex-pdftex-[0-9]*:../../print/tex-pdftex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
