# $NetBSD: Makefile,v 1.9 2018/05/06 11:46:17 markd Exp $

DISTNAME=	hyphen-latin
PKGNAME=	tex-${DISTNAME}-3.1.2018
TEXLIVE_REV=	47375

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/lahyph
COMMENT=	Liturgical Latin hyphenation patterns
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	latin loadhyph-la.tex
TEX_HYPHEN_DAT+=	classiclatin loadhyph-la-x-classic.tex
TEX_HYPHEN_DEF+=	\\addlanguage{latin}{loadhyph-la.tex}{}{2}{2}
TEX_HYPHEN_DEF+=	\\addlanguage{classiclatin}{loadhyph-la-x-classic.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['latin']={ \
			  loader='loadhyph-la.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=2, \
			  synonyms={}, \
			  patterns='hyph-la.pat.txt', \
			  hyphenation='', \
			},
TEX_HYPHEN_LUA+=	['classiclatin']={ \
			  loader='loadhyph-la-x-classic.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=2, \
			  synonyms={}, \
			  patterns='hyph-la-x-classic.pat.txt', \
			  hyphenation='', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
