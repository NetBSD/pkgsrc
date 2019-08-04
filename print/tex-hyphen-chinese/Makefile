# $NetBSD: Makefile,v 1.11 2019/08/04 12:04:46 markd Exp $

DISTNAME=	hyphen-chinese
PKGNAME=	tex-${DISTNAME}-2019.51186
TEXLIVE_REV=	51186

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Chinese
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

#TEX_HYPHEN_DAT+=	pinyin loadhyph-zh-latn-pinyin.tex
#TEX_HYPHEN_DEF+=	\\addlanguage{pinyin}{loadhyph-zh-latn-pinyin.tex}{}{1}{1}
#TEX_HYPHEN_LUA+=	['pinyin']={ \
#			  loader='loadhyph-zh-latn-pinyin.tex', \
#			  lefthyphenmin=1, \
#			  righthyphenmin=1, \
#			  synonyms={}, \
#			  patterns='hyph-zh-latn-pinyin.pat.txt', \
#			  hyphenation='', \
#			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
