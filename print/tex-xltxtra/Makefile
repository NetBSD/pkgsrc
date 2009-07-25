# $NetBSD: Makefile,v 1.1.1.1 2009/07/25 07:53:46 minskim Exp $
# TeX Live Revision 9907

DISTNAME=	xltxtra
PKGNAME=	tex-${DISTNAME}-0.4

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Extras files for LaTeX users of XeTeX

DEPENDS+=	tex-ifxetex-[0-9]*:../../print/tex-ifxetex
DEPENDS+=	tex-etex-pkg-[0-9]*:../../print/tex-etex-pkg
DEPENDS+=	tex-fontspec-[0-9]*:../../fonts/tex-fontspec
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-xunicode-[0-9]*:../../print/tex-xunicode

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
