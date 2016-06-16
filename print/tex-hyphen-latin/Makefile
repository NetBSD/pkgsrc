# $NetBSD: Makefile,v 1.6 2016/06/16 04:06:07 markd Exp $

DISTNAME=	hyphen-latin
PKGNAME=	tex-${DISTNAME}-3.1.2016
TEXLIVE_REV=	41189

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for the Latin language
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb12
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
