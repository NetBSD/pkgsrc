# $NetBSD: Makefile,v 1.17 2019/12/06 20:21:49 markd Exp $

DISTNAME=	latex
PKGNAME=	tex-${DISTNAME}-20181201
TEXLIVE_REV=	49390

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/latex
COMMENT=	TeX macro package that defines LaTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latexconfig>=2011:../../print/tex-latexconfig
DEPENDS+=	tex-latex-fonts-[0-9]*:../../fonts/tex-latex-fonts
DEPENDS+=	tex-luatex-[0-9]*:../../print/tex-luatex
DEPENDS+=	tex-pdftex-[0-9]*:../../print/tex-pdftex

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
