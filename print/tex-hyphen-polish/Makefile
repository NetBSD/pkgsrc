# $NetBSD: Makefile,v 1.3 2010/11/08 16:45:11 minskim Exp $

DISTNAME=	hyphen-polish
PKGNAME=	tex-${DISTNAME}-3.0a
TEXLIVE_REV=	20144

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation for Polish

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	polish loadhyph-pl.tex
TEX_HYPHEN_DEF+=	\addlanguage{polish}{loadhyph-pl.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['polish']={ \
			\\tloader='loadhyph-pl.tex', \
			\\tlefthyphenmin=2, \
			\\trighthyphenmin=2, \
			\\tsynonyms={}, \
			\\tpatterns='hyph-pl.pat.txt', \
			\\thyphenation='hyph-pl.hyp.txt', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
