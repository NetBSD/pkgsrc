# $NetBSD: Makefile,v 1.6 2013/11/17 17:25:40 minskim Exp $

DISTNAME=	hyphen-ancientgreek
PKGNAME=	tex-${DISTNAME}-2013
TEXLIVE_REV=	29725

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for ancient Greek

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	ancientgreek loadhyph-grc.tex
TEX_HYPHEN_DAT+=	ibycus ibyhyph.tex
TEX_HYPHEN_DEF+=	\addlanguage{ancientgreek}{loadhyph-grc.tex}{}{1}{1}
TEX_HYPHEN_DEF+=	\addlanguage{ibycus}{ibyhyph.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['ancientgreek']={ \
			  loader='loadhyph-grc.tex', \
			  lefthyphenmin=1, \
			  righthyphenmin=1, \
			  synonyms={}, \
			  patterns='hyph-grc.pat.txt', \
			  hyphenation='', \
			},
TEX_HYPHEN_LUA+=	['ibycus']={ \
			  loader='ibyhyph.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=2, \
			  synonyms={}, \
			  special='disabled:8-bit+only', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
