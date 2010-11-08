# $NetBSD: Makefile,v 1.3 2010/11/08 00:54:57 minskim Exp $

DISTNAME=	hyphen-catalan
PKGNAME=	tex-${DISTNAME}-2010
TEXLIVE_REV=	20144

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Catalan

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	catalan loadhyph-ca.tex
TEX_HYPHEN_DEF+=	\addlanguage{catalan}{loadhyph-ca.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['catalan']={ \
			\\tloader='loadhyph-ca.tex', \
			\\tlefthyphenmin=2, \
			\\trighthyphenmin=2, \
			\\tsynonyms={}, \
			\\tpatterns='hyph-ca.pat.txt', \
			\\thyphenation='hyph-ca.hyp.txt', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
