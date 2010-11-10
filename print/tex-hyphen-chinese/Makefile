# $NetBSD: Makefile,v 1.4 2010/11/10 17:55:28 minskim Exp $

DISTNAME=	hyphen-chinese
PKGNAME=	tex-${DISTNAME}-2010
PKGREVISION=	1
TEXLIVE_REV=	20144

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Chinese

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	pinyin loadhyph-zh-latn.tex
TEX_HYPHEN_DEF+=	\addlanguage{pinyin}{loadhyph-zh-latn.tex}{}{1}{1}
TEX_HYPHEN_LUA+=	['pinyin']={ \
			  loader='loadhyph-zh-latn.tex', \
			  lefthyphenmin=1, \
			  righthyphenmin=1, \
			  synonyms={}, \
			  patterns='hyph-zh-latn.pat.txt', \
			  hyphenation='', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
