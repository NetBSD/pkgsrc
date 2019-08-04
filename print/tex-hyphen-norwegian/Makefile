# $NetBSD: Makefile,v 1.10 2019/08/04 20:07:57 markd Exp $

DISTNAME=	hyphen-norwegian
PKGNAME=	tex-${DISTNAME}-2019.51186
TEXLIVE_REV=	51186

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Norwegian
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	bokmal loadhyph-nb.tex
TEX_HYPHEN_DAT+=	= norwegian
TEX_HYPHEN_DAT+=	= norsk
TEX_HYPHEN_DAT+=	nynorsk loadhyph-nn.tex
TEX_HYPHEN_DEF+=	\\addlanguage{bokmal}{loadhyph-nb.tex}{}{2}{2}
TEX_HYPHEN_DEF+=	\\addlanguage{norwegian}{loadhyph-nb.tex}{}{2}{2}
TEX_HYPHEN_DEF+=	\\addlanguage{norsk}{loadhyph-nb.tex}{}{2}{2}
TEX_HYPHEN_DEF+=	\\addlanguage{nynorsk}{loadhyph-nn.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['bokmal']={ \
			  loader='loadhyph-nb.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=2, \
			  synonyms={'norwegian','norsk',}, \
			  patterns='hyph-nb.pat.txt', \
			  hyphenation='hyph-nb.hyp.txt', \
			},
TEX_HYPHEN_LUA+=	['nynorsk']={ \
			  loader='loadhyph-nn.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=2, \
			  synonyms={}, \
			  patterns='hyph-nn.pat.txt', \
			  hyphenation='hyph-nn.hyp.txt', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
