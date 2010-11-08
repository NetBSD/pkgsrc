# $NetBSD: Makefile,v 1.4 2010/11/08 16:56:08 minskim Exp $

DISTNAME=	hyphen-greek
PKGNAME=	tex-${DISTNAME}-5
TEXLIVE_REV=	20144

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
			\\tloader='loadhyph-el-monoton.tex', \
			\\tlefthyphenmin=1, \
			\\trighthyphenmin=1, \
			\\tsynonyms={}, \
			\\tpatterns='hyph-el-monoton.pat.txt', \
			\\thyphenation='', \
			},
TEX_HYPHEN_LUA+=	['greek']={ \
			\\tloader='loadhyph-el-polyton.tex', \
			\\tlefthyphenmin=1, \
			\\trighthyphenmin=1, \
			\\tsynonyms={'polygreek',}, \
			\\tpatterns='hyph-el-polyton.pat.txt', \
			\\thyphenation='', \
			},
TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
