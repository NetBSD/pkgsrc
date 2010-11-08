# $NetBSD: Makefile,v 1.3 2010/11/08 16:44:45 minskim Exp $

DISTNAME=	hyphen-indonesian
PKGNAME=	tex-${DISTNAME}-2010
TEXLIVE_REV=	20144

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Indonesian

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	indonesian loadhyph-id.tex
TEX_HYPHEN_DEF+=	\addlanguage{indonesian}{loadhyph-id.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['indonesian']={ \
			\\tloader='loadhyph-id.tex', \
			\\tlefthyphenmin=2, \
			\\trighthyphenmin=2, \
			\\tsynonyms={}, \
			\\tpatterns='hyph-id.pat.txt', \
			\\thyphenation='hyph-id.hyp.txt', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
