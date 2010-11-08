# $NetBSD: Makefile,v 1.3 2010/11/08 16:03:57 minskim Exp $

DISTNAME=	hyphen-chinese
PKGNAME=	tex-${DISTNAME}-2010
TEXLIVE_REV=	20144

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Chinese

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	pinyin loadhyph-zh-latn.tex
TEX_HYPHEN_DEF+=	\addlanguage{pinyin}{loadhyph-zh-latn.tex}{}{1}{1}
TEX_HYPHEN_LUA+=	['pinyin']={ \
			\\tloader='loadhyph-zh-latn.tex', \
			\\tlefthyphenmin=1, \
			\\trighthyphenmin=1, \
			\\tsynonyms={}, \
			\\tpatterns='hyph-zh-latn.pat.txt', \
			\\thyphenation='', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
