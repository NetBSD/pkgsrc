# $NetBSD: Makefile,v 1.6 2013/11/17 17:20:53 minskim Exp $

DISTNAME=	hyphen-greek
PKGNAME=	tex-${DISTNAME}-5
PKGREVISION=	2
TEXLIVE_REV=	29725

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation for Greek text

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	monogreek loadhyph-el-monoton.tex
TEX_HYPHEN_DAT+=	greek loadhyph-el-polyton.tex
TEX_HYPHEN_DAT+=	= polygreek
TEX_HYPHEN_DEF+=	\addlanguage{monogreek}{loadhyph-el-monoton.tex}{}{1}{1}
TEX_HYPHEN_DEF+=	\addlanguage{greek}{loadhyph-el-polyton.tex}{}{1}{1}
TEX_HYPHEN_DEF+=	\addlanguage{polygreek}{loadhyph-el-polyton.tex}{}{1}{1}
TEX_HYPHEN_LUA+=	['monogreek']={ \
			  loader='loadhyph-el-monoton.tex', \
			  lefthyphenmin=1, \
			  righthyphenmin=1, \
			  synonyms={}, \
			  patterns='hyph-el-monoton.pat.txt', \
			  hyphenation='', \
			},
TEX_HYPHEN_LUA+=	['greek']={ \
			  loader='loadhyph-el-polyton.tex', \
			  lefthyphenmin=1, \
			  righthyphenmin=1, \
			  synonyms={'polygreek',}, \
			  patterns='hyph-el-polyton.pat.txt', \
			  hyphenation='', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
