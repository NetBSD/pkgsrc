# $NetBSD: Makefile,v 1.3 2010/11/08 00:40:07 minskim Exp $

DISTNAME=	dehyph-exptl
PKGNAME=	tex-${DISTNAME}-0.20
PKGREVISION=	1
TEXLIVE_REV=	18640

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Experimental hyphenation patterns for the German language

CONFLICTS+=	teTeX-texmf<=3.0nb12

TEX_HYPHEN_DAT+=	german-x-2009-06-19 dehypht-x-2009-06-19.tex
TEX_HYPHEN_DAT+=	= german-x-latest
TEX_HYPHEN_DAT+=	ngerman-x-2009-06-19 dehyphn-x-2009-06-19.tex
TEX_HYPHEN_DAT+=	= ngerman-x-latest
TEX_HYPHEN_DEF+=	\addlanguage{german-x-2009-06-19}{dehypht-x-2009-06-19.tex}{}{2}{2}
TEX_HYPHEN_DEF+=	\addlanguage{german-x-latest}{dehypht-x-2009-06-19.tex}{}{2}{2}
TEX_HYPHEN_DEF+=	\addlanguage{ngerman-x-2009-06-19}{dehyphn-x-2009-06-19.tex}{}{2}{2}
TEX_HYPHEN_DEF+=	\addlanguage{ngerman-x-latest}{dehyphn-x-2009-06-19.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['german-x-2009-06-19']={ \
			\\tloader='dehypht-x-2009-06-19.tex', \
			\\tlefthyphenmin=2, \
			\\trighthyphenmin=2, \
			\\tsynonyms={'german-x-latest',}, \
			\\tpatterns='hyph-de-1901.pat.txt', \
			\\thyphenation='hyph-de-1901.hyp.txt', \
			},
TEX_HYPHEN_LUA+=	['ngerman-x-2009-06-19']={ \
			\\tloader='dehyphn-x-2009-06-19.tex', \
			\\tlefthyphenmin=2, \
			\\trighthyphenmin=2, \
			\\tsynonyms={'ngerman-x-latest',}, \
			\\tpatterns='hyph-de-1996.pat.txt', \
			\\thyphenation='hyph-de-1996.hyp.txt', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
