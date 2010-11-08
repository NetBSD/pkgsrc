# $NetBSD: Makefile,v 1.3 2010/11/08 16:49:08 minskim Exp $

DISTNAME=	hyphen-portuguese
PKGNAME=	tex-${DISTNAME}-2010
TEXLIVE_REV=	20144

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Portuguese

CONFLICTS+=	teTeX-texmf<=3.0nb24
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	portuguese loadhyph-pt.tex
TEX_HYPHEN_DAT+=	= portuges
TEX_HYPHEN_DEF+=	\addlanguage{portuguese}{loadhyph-pt.tex}{}{2}{3}
TEX_HYPHEN_DEF+=	\addlanguage{portuges}{loadhyph-pt.tex}{}{2}{3}
TEX_HYPHEN_LUA+=	['portuguese']={ \
			\\tloader='loadhyph-pt.tex', \
			\\tlefthyphenmin=2, \
			\\trighthyphenmin=3, \
			\\tsynonyms={'portuges',}, \
			\\tpatterns='hyph-pt.pat.txt', \
			\\thyphenation='hyph-pt.hyp.txt', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
