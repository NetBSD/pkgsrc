# $NetBSD: Makefile,v 1.3 2010/11/08 16:26:24 minskim Exp $

DISTNAME=	hyphen-esperanto
PKGNAME=	tex-${DISTNAME}-2010
TEXLIVE_REV=	20144

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Esperanto

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	esperanto loadhyph-eo.tex
TEX_HYPHEN_DEF+=	\addlanguage{esperanto}{loadhyph-eo.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['esperanto']={ \
			\\tloader='loadhyph-eo.tex', \
			\\tlefthyphenmin=2, \
			\\trighthyphenmin=2, \
			\\tsynonyms={}, \
			\\tpatterns='hyph-eo.pat.txt', \
			\\thyphenation='', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
