# $NetBSD: Makefile,v 1.1 2015/05/16 02:51:22 markd Exp $

DISTNAME=	hyphen-ethiopic
PKGNAME=	tex-${DISTNAME}-2014
TEXLIVE_REV=	23085

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Hyphenation patterns for Ethiopic scripts

DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	ethiopic loadhyph-mul-ethi.tex
TEX_HYPHEN_DAT+=	= amharic
TEX_HYPHEN_DAT+=	= geez
TEX_HYPHEN_DEF+=	\\addlanguage{ethiopic}{loadhyph-mul-ethi.tex}{}{1}{1}
TEX_HYPHEN_DEF+=	\\addlanguage{amharic}{loadhyph-mul-ethi.tex}{}{1}{1}
TEX_HYPHEN_DEF+=	\\addlanguage{geez}{loadhyph-mul-ethi.tex}{}{1}{1}
TEX_HYPHEN_LUA+=	['ethiopic']={ \
			  loader='loadhyph-mul-ethi.tex', \
			  lefthyphenmin=1, \
			  righthyphenmin=1, \
			  synonyms={'amharic','geez',}, \
			  patterns='hyph-mul-ethi.pat.txt', \
			  hyphenation='', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
