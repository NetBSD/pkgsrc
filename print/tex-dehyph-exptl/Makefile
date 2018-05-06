# $NetBSD: Makefile,v 1.10 2018/05/06 02:30:07 markd Exp $

DISTNAME=	dehyph-exptl
PKGNAME=	tex-${DISTNAME}-0.5
TEXLIVE_REV=	47240

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/dehyph-exptl
COMMENT=	Experimental hyphenation patterns for the German language
LICENSE=	lppl-1.3c

TEX_HYPHEN_DAT+=	german-x-2018-03-31 dehypht-x-2018-03-31.tex
TEX_HYPHEN_DAT+=	= german-x-latest
TEX_HYPHEN_DAT+=	ngerman-x-2018-03-31 dehyphn-x-2018-03-31.tex
TEX_HYPHEN_DAT+=	= ngerman-x-latest
TEX_HYPHEN_DEF+=	\\addlanguage{german-x-2018-03-31}{dehypht-x-2018-03-31.tex}{}{2}{2}
TEX_HYPHEN_DEF+=	\\addlanguage{german-x-latest}{dehypht-x-2018-03-31.tex}{}{2}{2}
TEX_HYPHEN_DEF+=	\\addlanguage{ngerman-x-2018-03-31}{dehyphn-x-2018-03-31.tex}{}{2}{2}
TEX_HYPHEN_DEF+=	\\addlanguage{ngerman-x-latest}{dehyphn-x-2018-03-31.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['german-x-2018-03-31']={ \
			  loader='dehypht-x-2018-03-31.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=2, \
			  synonyms={'german-x-latest',}, \
			  patterns='hyph-de-1901.pat.txt', \
			  hyphenation='hyph-de-1901.hyp.txt', \
			},
TEX_HYPHEN_LUA+=	['ngerman-x-2018-03-31']={ \
			  loader='dehyphn-x-2018-03-31.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=2, \
			  synonyms={'ngerman-x-latest',}, \
			  patterns='hyph-de-1996.pat.txt', \
			  hyphenation='hyph-de-1996.hyp.txt', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
