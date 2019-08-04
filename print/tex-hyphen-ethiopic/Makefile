# $NetBSD: Makefile,v 1.5 2019/08/04 12:32:49 markd Exp $

DISTNAME=	hyphen-ethiopic
PKGNAME=	tex-${DISTNAME}-2019.51186
TEXLIVE_REV=	51186

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Hyphenation patterns for Ethiopic scripts
LICENSE=	lppl-1.3c

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
