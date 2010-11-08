# $NetBSD: Makefile,v 1.3 2010/11/08 16:45:24 minskim Exp $

DISTNAME=	hyphen-serbian
PKGNAME=	tex-${DISTNAME}-1.0a
TEXLIVE_REV=	20144

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Serbian Cyrillic

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	serbian loadhyph-sr-latn.tex
TEX_HYPHEN_DEF+=	\addlanguage{serbian}{loadhyph-sr-latn.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['serbian']={ \
			\\tloader='loadhyph-sr-latn.tex', \
			\\tlefthyphenmin=2, \
			\\trighthyphenmin=2, \
			\\tsynonyms={}, \
			\\tpatterns='hyph-sr-latn.pat.txt', \
			\\thyphenation='hyph-sr-latn.hyp.txt', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
