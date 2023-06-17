# $NetBSD: Makefile,v 1.25 2023/06/17 10:30:57 markd Exp $

DISTNAME=	latex
PKGNAME=	tex-${DISTNAME}-20230601.0
TEXLIVE_REV=	67314

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/latex
COMMENT=	TeX macro package that defines LaTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hypdoc-[0-9]*:../../print/tex-hypdoc
DEPENDS+=	tex-latex-fonts-[0-9]*:../../fonts/tex-latex-fonts
DEPENDS+=	tex-latexconfig-[0-9]*:../../print/tex-latexconfig
DEPENDS+=	tex-luatex-[0-9]*:../../print/tex-luatex
DEPENDS+=	tex-pdftex-[0-9]*:../../print/tex-pdftex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
