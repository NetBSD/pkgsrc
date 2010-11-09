# $NetBSD: Makefile,v 1.3 2010/11/09 16:10:55 minskim Exp $

DISTNAME=	hyphen-mongolian
PKGNAME=	tex-${DISTNAME}-2010
TEXLIVE_REV=	20144

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Mongolian

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	mongolian loadhyph-mn-cyrl.tex
TEX_HYPHEN_DAT+=	mongolianlmc loadhyph-mn-cyrl-x-lmc.tex
TEX_HYPHEN_DEF+=	\addlanguage{mongolian}{loadhyph-mn-cyrl.tex}{}{2}{2}
TEX_HYPHEN_DEF+=	\addlanguage{mongolianlmc}{loadhyph-mn-cyrl-x-lmc.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['mongolian']={ \
			\\tloader='loadhyph-mn-cyrl.tex', \
			\\tlefthyphenmin=2, \
			\\trighthyphenmin=2, \
			\\tsynonyms={}, \
			\\tpatterns='hyph-mn-cyrl.pat.txt', \
			\\thyphenation='', \
			},
TEX_HYPHEN_LUA+=	['mongolianlmc']={ \
			\\tloader='loadhyph-mn-cyrl-x-lmc.tex', \
			\\tlefthyphenmin=2, \
			\\trighthyphenmin=2, \
			\\tsynonyms={}, \
			\\tspecial='disabled:only+for+8bit+montex+with+lmc+encoding', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
