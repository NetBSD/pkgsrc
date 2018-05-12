# $NetBSD: Makefile,v 1.15 2018/05/12 03:21:30 markd Exp $

DISTNAME=	latex
PKGNAME=	tex-${DISTNAME}-20170101.3
TEXLIVE_REV=	47500

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/latex
COMMENT=	TeX macro package that defines LaTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latexconfig>=2011:../../print/tex-latexconfig
DEPENDS+=	tex-latex-fonts-[0-9]*:../../fonts/tex-latex-fonts
DEPENDS+=	tex-luatex-[0-9]*:../../print/tex-luatex
DEPENDS+=	tex-pdftex-[0-9]*:../../print/tex-pdftex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
