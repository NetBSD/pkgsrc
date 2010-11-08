# $NetBSD: Makefile,v 1.3 2010/11/08 16:44:49 minskim Exp $

DISTNAME=	hyphen-interlingua
PKGNAME=	tex-${DISTNAME}-2010
TEXLIVE_REV=	20144

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Interlingua

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	interlingua loadhyph-ia.tex
TEX_HYPHEN_DEF+=	\addlanguage{interlingua}{loadhyph-ia.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['interlingua']={ \
			\\tloader='loadhyph-ia.tex', \
			\\tlefthyphenmin=2, \
			\\trighthyphenmin=2, \
			\\tsynonyms={}, \
			\\tpatterns='hyph-ia.pat.txt', \
			\\thyphenation='hyph-ia.hyp.txt', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
