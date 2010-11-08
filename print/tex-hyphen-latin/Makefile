# $NetBSD: Makefile,v 1.3 2010/11/08 16:44:59 minskim Exp $

DISTNAME=	hyphen-latin
PKGNAME=	tex-${DISTNAME}-3.1
TEXLIVE_REV=	20144

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for the Latin language

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	latin loadhyph-la.tex
TEX_HYPHEN_DEF+=	\addlanguage{latin}{loadhyph-la.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['latin']={ \
			\\tloader='loadhyph-la.tex', \
			\\tlefthyphenmin=2, \
			\\trighthyphenmin=2, \
			\\tsynonyms={}, \
			\\tpatterns='hyph-la.pat.txt', \
			\\thyphenation='', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
