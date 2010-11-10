# $NetBSD: Makefile,v 1.5 2010/11/10 17:55:27 minskim Exp $

DISTNAME=	hyphen-ancientgreek
PKGNAME=	tex-${DISTNAME}-2010
PKGREVISION=	1
TEXLIVE_REV=	20144

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
TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
