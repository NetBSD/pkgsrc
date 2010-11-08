# $NetBSD: Makefile,v 1.3 2010/11/08 16:45:28 minskim Exp $

DISTNAME=	hyphen-slovak
PKGNAME=	tex-${DISTNAME}-2010
TEXLIVE_REV=	20144

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Slovak

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	slovak loadhyph-sk.tex
TEX_HYPHEN_DEF+=	\addlanguage{slovak}{loadhyph-sk.tex}{}{2}{3}
TEX_HYPHEN_LUA+=	['slovak']={ \
			\\tloader='loadhyph-sk.tex', \
			\\tlefthyphenmin=2, \
			\\trighthyphenmin=3, \
			\\tsynonyms={}, \
			\\tpatterns='hyph-sk.pat.txt', \
			\\thyphenation='hyph-sk.hyp.txt', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
