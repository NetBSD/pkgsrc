# $NetBSD: Makefile,v 1.13 2021/05/30 08:04:46 markd Exp $

DISTNAME=	hyphen-lithuanian
PKGNAME=	tex-${DISTNAME}-2021
TEXLIVE_REV=	58652

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Lithuanian
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base

TEX_HYPHEN_DAT+=	lithuanian loadhyph-lt.tex
TEX_HYPHEN_DEF+=	\\addlanguage{lithuanian}{loadhyph-lt.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['lithuanian']={ \
			  loader='loadhyph-lt.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=2, \
			  synonyms={}, \
			  patterns='hyph-lt.pat.txt', \
			  hyphenation='', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
