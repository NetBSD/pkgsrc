# $NetBSD: Makefile,v 1.3 2010/11/08 00:51:49 minskim Exp $

DISTNAME=	hyphen-bulgarian
PKGNAME=	tex-${DISTNAME}-2010
TEXLIVE_REV=	20144

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Bulgarian

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	bulgarian loadhyph-bg.tex
TEX_HYPHEN_DEF+=	\addlanguage{bulgarian}{loadhyph-bg.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['bulgarian']={ \
			\\tloader='loadhyph-bg.tex', \
			\\tlefthyphenmin=2, \
			\\trighthyphenmin=2, \
			\\tsynonyms={}, \
			\\tpatterns='hyph-bg.pat.txt', \
			\\thyphenation='', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
