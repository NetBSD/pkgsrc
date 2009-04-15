# $NetBSD: Makefile,v 1.1.1.1 2009/04/15 07:52:43 minskim Exp $
# TeX Live Revision 9404

DISTNAME=	hyphen-ukenglish
PKGNAME=	tex-${DISTNAME}-2008.9404

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for UK English

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	ukenglish loadhyph-en-gb.tex
TEX_HYPHEN_DAT+=	= british
TEX_HYPHEN_DAT+=	= UKenglish
TEX_HYPHEN_DEF+=	\addlanguage{ukenglish}{loadhyph-en-gb.tex}{}{2}{3}
TEX_HYPHEN_DEF+=	\addlanguage{british}{loadhyph-en-gb.tex}{}{2}{3}
TEX_HYPHEN_DEF+=	\addlanguage{UKenglish}{loadhyph-en-gb.tex}{}{2}{3}

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
