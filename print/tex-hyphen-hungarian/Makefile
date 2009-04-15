# $NetBSD: Makefile,v 1.1.1.1 2009/04/15 07:38:15 minskim Exp $
# TeX Live Revision 9116

DISTNAME=	hyphen-hungarian
PKGNAME=	tex-${DISTNAME}-2008.9116

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Hungarian

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	hungarian loadhyph-hu.tex
TEX_HYPHEN_DEF+=	\addlanguage{hungarian}{loadhyph-hu.tex}{}{2}{2}

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
