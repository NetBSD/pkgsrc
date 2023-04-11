# $NetBSD: Makefile,v 1.18 2023/04/11 00:14:40 markd Exp $

DISTNAME=	dehyph-exptl
PKGNAME=	tex-${DISTNAME}-0.9
TEXLIVE_REV=	66390

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/dehyph-exptl
COMMENT=	Experimental hyphenation patterns for the German language
LICENSE=	mit AND lppl-1.3c

TEX_HYPHEN_DAT+=	german-x-2023-03-06 dehypht-x-2023-03-06.tex
TEX_HYPHEN_DAT+=	= german-x-latest
TEX_HYPHEN_DAT+=	ngerman-x-2023-03-06 dehyphn-x-2023-03-06.tex
TEX_HYPHEN_DAT+=	= ngerman-x-latest
TEX_HYPHEN_DEF+=	\\addlanguage{german-x-2023-03-06}{dehypht-x-2023-03-06.tex}{}{2}{2}
TEX_HYPHEN_DEF+=	\\addlanguage{german-x-latest}{dehypht-x-2023-03-06.tex}{}{2}{2}
TEX_HYPHEN_DEF+=	\\addlanguage{ngerman-x-2023-03-06}{dehyphn-x-2023-03-06.tex}{}{2}{2}
TEX_HYPHEN_DEF+=	\\addlanguage{ngerman-x-latest}{dehyphn-x-2023-03-06.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['german-x-2023-03-06']={ \
			  loader='dehypht-x-2023-03-06.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=2, \
			  synonyms={'german-x-latest',}, \
			  patterns='hyph-de-1901.pat.txt', \
			  hyphenation='', \
			},
TEX_HYPHEN_LUA+=	['ngerman-x-2023-03-06']={ \
			  loader='dehyphn-x-2023-03-06.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=2, \
			  synonyms={'ngerman-x-latest',}, \
			  patterns='hyph-de-1996.pat.txt', \
			  hyphenation='', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
