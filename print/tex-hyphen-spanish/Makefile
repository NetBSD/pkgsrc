# $NetBSD: Makefile,v 1.1.1.1 2009/04/15 07:50:34 minskim Exp $
# TeX Live Revision 8996

DISTNAME=	hyphen-spanish
PKGNAME=	tex-${DISTNAME}-4.2a

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Spanish

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	spanish loadhyph-es.tex
TEX_HYPHEN_DAT+=	= espanol
TEX_HYPHEN_DEF+=	\addlanguage{spanish}{loadhyph-es.tex}{}{2}{2}
TEX_HYPHEN_DEF+=	\addlanguage{espanol}{loadhyph-es.tex}{}{2}{2}

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
