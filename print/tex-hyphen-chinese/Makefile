# $NetBSD: Makefile,v 1.17 2026/03/26 08:07:41 markd Exp $

DISTNAME=	hyphen-chinese
PKGNAME=	tex-${DISTNAME}-2026
TEXLIVE_REV=	78069

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Chinese
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base

TEX_HYPHEN_DAT+=	pinyin loadhyph-zh-latn-pinyin.tex
TEX_HYPHEN_DEF+=	\\addlanguage{pinyin}{loadhyph-zh-latn-pinyin.tex}{}{1}{2}
TEX_HYPHEN_LUA+=	['pinyin']={ \
			  loader='loadhyph-zh-latn-pinyin.tex', \
			  lefthyphenmin=1, \
			  righthyphenmin=2, \
			  synonyms={}, \
			  patterns='hyph-zh-latn-pinyin.pat.txt', \
			  hyphenation='', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
