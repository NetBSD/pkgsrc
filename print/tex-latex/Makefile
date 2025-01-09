# $NetBSD: Makefile,v 1.27 2025/01/09 09:51:56 markd Exp $

DISTNAME=	latex
PKGNAME=	tex-${DISTNAME}-20240601.2
TEXLIVE_REV=	71629

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
