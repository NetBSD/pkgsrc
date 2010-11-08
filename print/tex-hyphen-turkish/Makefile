# $NetBSD: Makefile,v 1.3 2010/11/08 16:45:38 minskim Exp $

DISTNAME=	hyphen-turkish
PKGNAME=	tex-${DISTNAME}-2010
TEXLIVE_REV=	20144

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Turkish

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	turkish loadhyph-tr.tex
TEX_HYPHEN_DEF+=	\addlanguage{turkish}{loadhyph-tr.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['turkish']={ \
			\\tloader='loadhyph-tr.tex', \
			\\tlefthyphenmin=2, \
			\\trighthyphenmin=2, \
			\\tsynonyms={}, \
			\\tpatterns='hyph-tr.pat.txt', \
			\\thyphenation='', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
