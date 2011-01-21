# $NetBSD: Makefile,v 1.1.1.1 2011/01/21 17:56:02 minskim Exp $

DISTNAME=	xetex
PKGNAME=	tex-${DISTNAME}-2010
TEXLIVE_REV=	18937

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Unicode and OpenType-enabled TeX engine

DEPENDS+=	tex-etex>=2.1:../../print/tex-etex
DEPENDS+=	tex-latex>=2010:../../print/tex-latex
DEPENDS+=	tex-latexconfig>=2010.20663:../../print/tex-latexconfig
DEPENDS+=	tex-plain>=3.141592653nb2:../../print/tex-plain
DEPENDS+=	tex-xetexconfig>=2010:../../print/tex-xetexconfig
DEPENDS+=	xetex>=0.9995.3nb1:../../print/xetex

TEX_FORMATS+=		"xetex xetex language.def -etex xetex.ini\\nxelatex xetex language.dat -etex xelatex.ini\\n"
TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
