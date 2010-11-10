# $NetBSD: Makefile,v 1.4 2010/11/10 17:55:27 minskim Exp $

DISTNAME=	dehyph-exptl
PKGNAME=	tex-${DISTNAME}-0.20
PKGREVISION=	2
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
			  loader='dehypht-x-2009-06-19.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=2, \
			  synonyms={'german-x-latest',}, \
			  patterns='hyph-de-1901.pat.txt', \
			  hyphenation='hyph-de-1901.hyp.txt', \
			},
TEX_HYPHEN_LUA+=	['ngerman-x-2009-06-19']={ \
			  loader='dehyphn-x-2009-06-19.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=2, \
			  synonyms={'ngerman-x-latest',}, \
			  patterns='hyph-de-1996.pat.txt', \
			  hyphenation='hyph-de-1996.hyp.txt', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
