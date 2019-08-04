# $NetBSD: Makefile,v 1.12 2019/08/04 12:49:35 markd Exp $

DISTNAME=	hyphen-greek
PKGNAME=	tex-${DISTNAME}-2019.51186
TEXLIVE_REV=	51186

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation for Greek text
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	monogreek loadhyph-el-monoton.tex
TEX_HYPHEN_DAT+=	greek loadhyph-el-polyton.tex
TEX_HYPHEN_DAT+=	= polygreek
TEX_HYPHEN_DEF+=	\\addlanguage{monogreek}{loadhyph-el-monoton.tex}{}{1}{1}
TEX_HYPHEN_DEF+=	\\addlanguage{greek}{loadhyph-el-polyton.tex}{}{1}{1}
TEX_HYPHEN_DEF+=	\\addlanguage{polygreek}{loadhyph-el-polyton.tex}{}{1}{1}
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
