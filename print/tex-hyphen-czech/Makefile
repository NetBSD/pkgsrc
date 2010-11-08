# $NetBSD: Makefile,v 1.3 2010/11/08 16:20:26 minskim Exp $

DISTNAME=	hyphen-czech
PKGNAME=	tex-${DISTNAME}-2010
TEXLIVE_REV=	20144

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Czech

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	czech loadhyph-cs.tex
TEX_HYPHEN_DEF+=	\addlanguage{czech}{loadhyph-cs.tex}{}{2}{3}
TEX_HYPHEN_LUA+=	['czech']={ \
			\\tloader='loadhyph-cs.tex', \
			\\tlefthyphenmin=2, \
			\\trighthyphenmin=3, \
			\\tsynonyms={}, \
			\\tpatterns='hyph-cs.pat.txt', \
			\\thyphenation='hyph-cs.hyp.txt', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
