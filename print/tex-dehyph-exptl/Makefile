# $NetBSD: Makefile,v 1.1.1.1 2009/04/15 05:25:38 minskim Exp $
# TeX Live Revision 9413

DISTNAME=	dehyph-exptl
PKGNAME=	tex-${DISTNAME}-0.13

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Experimental hyphenation patterns for the German language

CONFLICTS+=	teTeX-texmf<=3.0nb12

TEX_HYPHEN_DAT+=	german-x-2008-06-18 dehypht-x-2008-06-18.tex
TEX_HYPHEN_DAT+=	= german-x-latest
TEX_HYPHEN_DAT+=	ngerman-x-2008-06-18 dehyphn-x-2008-06-18.tex
TEX_HYPHEN_DAT+=	= ngerman-x-latest
TEX_HYPHEN_DEF+=	\addlanguage{german-x-2008-06-18}{dehypht-x-2008-06-18.tex}{}{2}{2}
TEX_HYPHEN_DEF+=	\addlanguage{german-x-latest}{dehypht-x-2008-06-18.tex}{}{2}{2}
TEX_HYPHEN_DEF+=	\addlanguage{ngerman-x-2008-06-18}{dehyphn-x-2008-06-18.tex}{}{2}{2}
TEX_HYPHEN_DEF+=	\addlanguage{ngerman-x-latest}{dehyphn-x-2008-06-18.tex}{}{2}{2}

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
