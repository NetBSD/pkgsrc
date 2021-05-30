# $NetBSD: Makefile,v 1.10 2021/05/30 08:04:44 markd Exp $

DISTNAME=	hyphen-english
PKGNAME=	tex-${DISTNAME}-2021
TEXLIVE_REV=	58609

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	English hyphenation patterns
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base

TEX_HYPHEN_DAT+=	usenglishmax loadhyph-en-us.tex
TEX_HYPHEN_DAT+=	ukenglish loadhyph-en-gb.tex
TEX_HYPHEN_DAT+=	= british
TEX_HYPHEN_DAT+=	= UKenglish
TEX_HYPHEN_DEF+=	\\addlanguage{usenglishmax}{loadhyph-en-us.tex}{}{2}{3}
TEX_HYPHEN_DEF+=	\\addlanguage{ukenglish}{loadhyph-en-gb.tex}{}{2}{3}
TEX_HYPHEN_DEF+=	\\addlanguage{british}{loadhyph-en-gb.tex}{}{2}{3}
TEX_HYPHEN_DEF+=	\\addlanguage{UKenglish}{loadhyph-en-gb.tex}{}{2}{3}

TEX_HYPHEN_LUA+=	['usenglishmax']={ \
			  loader='loadhyph-en-us.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=3, \
			  synonyms={}, \
			  patterns='hyph-en-us.pat.txt', \
			  hyphenation='hyph-en-us.hyp.txt', \
			},
TEX_HYPHEN_LUA+=	['ukenglish']={ \
			  loader='loadhyph-en-gb.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=3, \
			  synonyms={'british','UKenglish',}, \
			  patterns='hyph-en-gb.pat.txt', \
			  hyphenation='hyph-en-gb.hyp.txt', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
