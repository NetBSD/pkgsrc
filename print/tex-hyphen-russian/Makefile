# $NetBSD: Makefile,v 1.3 2010/11/08 16:45:18 minskim Exp $

DISTNAME=	hyphen-russian
PKGNAME=	tex-${DISTNAME}-2010
TEXLIVE_REV=	20144

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Russian

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	russian loadhyph-ru.tex
TEX_HYPHEN_DEF+=	\addlanguage{russian}{loadhyph-ru.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['russian']={ \
			\\tloader='loadhyph-ru.tex', \
			\\tlefthyphenmin=2, \
			\\trighthyphenmin=2, \
			\\tsynonyms={}, \
			\\tpatterns='hyph-ru.pat.txt', \
			\\thyphenation='hyph-ru.hyp.txt', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
