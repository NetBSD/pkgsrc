# $NetBSD: Makefile,v 1.4 2010/11/08 16:45:44 minskim Exp $

DISTNAME=	hyphen-uppersorbian
PKGNAME=	tex-${DISTNAME}-2010
TEXLIVE_REV=	20144

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Upper Sorbian

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	uppersorbian loadhyph-hsb.tex
TEX_HYPHEN_DEF+=	\addlanguage{uppersorbian}{loadhyph-hsb.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['uppersorbian']={ \
			\\tloader='loadhyph-hsb.tex', \
			\\tlefthyphenmin=2, \
			\\trighthyphenmin=2, \
			\\tsynonyms={}, \
			\\tpatterns='hyph-hsb.pat.txt', \
			\\thyphenation='hyph-hsb.hyp.txt', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
