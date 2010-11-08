# $NetBSD: Makefile,v 1.3 2010/11/08 16:45:04 minskim Exp $

DISTNAME=	hyphen-lithuanian
PKGNAME=	tex-${DISTNAME}-2010
TEXLIVE_REV=	20144

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Lithuanian

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	lithuanian loadhyph-lt.tex
TEX_HYPHEN_DEF+=	\addlanguage{lithuanian}{loadhyph-lt.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['lithuanian']={ \
			\\tloader='loadhyph-lt.tex', \
			\\tlefthyphenmin=2, \
			\\trighthyphenmin=2, \
			\\tsynonyms={}, \
			\\tpatterns='hyph-lt.pat.txt', \
			\\thyphenation='', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
