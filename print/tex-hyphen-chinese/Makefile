# $NetBSD: Makefile,v 1.6 2015/05/05 12:23:56 markd Exp $

DISTNAME=	hyphen-chinese
PKGNAME=	tex-${DISTNAME}-2014
TEXLIVE_REV=	25990

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Chinese

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	pinyin loadhyph-zh-latn-pinyin.tex
TEX_HYPHEN_DEF+=	\\addlanguage{pinyin}{loadhyph-zh-latn-pinyin.tex}{}{1}{1}
TEX_HYPHEN_LUA+=	['pinyin']={ \
			  loader='loadhyph-zh-latn-pinyin.tex', \
			  lefthyphenmin=1, \
			  righthyphenmin=1, \
			  synonyms={}, \
			  patterns='hyph-zh-latn-pinyin.pat.txt', \
			  hyphenation='', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
