# $NetBSD: Makefile,v 1.3 2010/11/08 16:45:07 minskim Exp $

DISTNAME=	hyphen-norwegian
PKGNAME=	tex-${DISTNAME}-2010
TEXLIVE_REV=	20144

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Norwegian

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	bokmal loadhyph-nb.tex
TEX_HYPHEN_DAT+=	= norwegian
TEX_HYPHEN_DAT+=	= norsk
TEX_HYPHEN_DAT+=	nynorsk loadhyph-nn.tex
TEX_HYPHEN_DEF+=	\addlanguage{bokmal}{loadhyph-nb.tex}{}{2}{2}
TEX_HYPHEN_DEF+=	\addlanguage{norwegian}{loadhyph-nb.tex}{}{2}{2}
TEX_HYPHEN_DEF+=	\addlanguage{norsk}{loadhyph-nb.tex}{}{2}{2}
TEX_HYPHEN_DEF+=	\addlanguage{nynorsk}{loadhyph-nn.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['bokmal']={ \
			\\tloader='loadhyph-nb.tex', \
			\\tlefthyphenmin=2, \
			\\trighthyphenmin=2, \
			\\tsynonyms={'norwegian','norsk',}, \
			\\tpatterns='hyph-nb.pat.txt', \
			\\thyphenation='hyph-nb.hyp.txt', \
			},
TEX_HYPHEN_LUA+=	['nynorsk']={ \
			\\tloader='loadhyph-nn.tex', \
			\\tlefthyphenmin=2, \
			\\trighthyphenmin=2, \
			\\tsynonyms={}, \
			\\tpatterns='hyph-nn.pat.txt', \
			\\thyphenation='hyph-nn.hyp.txt', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
