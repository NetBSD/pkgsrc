# $NetBSD: Makefile,v 1.2 2010/05/19 23:13:07 minskim Exp $

DISTNAME=	xltxtra
PKGNAME=	tex-${DISTNAME}-0.5b
TEXLIVE_REV=	16545

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Extras files for LaTeX users of XeTeX

DEPENDS+=	tex-ifxetex-[0-9]*:../../print/tex-ifxetex
DEPENDS+=	tex-etex-pkg-[0-9]*:../../print/tex-etex-pkg
DEPENDS+=	tex-fontspec-[0-9]*:../../fonts/tex-fontspec
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-xunicode-[0-9]*:../../print/tex-xunicode

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
