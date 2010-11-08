# $NetBSD: Makefile,v 1.3 2010/11/08 16:44:55 minskim Exp $

DISTNAME=	hyphen-italian
PKGNAME=	tex-${DISTNAME}-4.8g
TEXLIVE_REV=	20144

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for the Italian language

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	italian loadhyph-it.tex
TEX_HYPHEN_DEF+=	\addlanguage{italian}{loadhyph-it.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['italian']={ \
			\\tloader='loadhyph-it.tex', \
			\\tlefthyphenmin=2, \
			\\trighthyphenmin=2, \
			\\tsynonyms={}, \
			\\tpatterns='hyph-it.pat.txt', \
			\\thyphenation='', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
