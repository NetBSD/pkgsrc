# $NetBSD: Makefile,v 1.4 2010/11/08 00:28:46 minskim Exp $

DISTNAME=	hyphen-ancientgreek
PKGNAME=	tex-${DISTNAME}-2010
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
			\\tloader='loadhyph-grc.tex', \
			\\tlefthyphenmin=1, \
			\\trighthyphenmin=1, \
			\\tsynonyms={}, \
			\\tpatterns='hyph-grc.pat.txt', \
			\\thyphenation='', \
			},
TEX_HYPHEN_LUA+=	['ibycus']={ \
			\\tloader='ibyhyph.tex', \
			\\tlefthyphenmin=2, \
			\\trighthyphenmin=2, \
			\\tsynonyms={}, \
			\\tspecial='disabled:8-bit+only', \
			},
TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
