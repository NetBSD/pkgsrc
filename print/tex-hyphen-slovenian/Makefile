# $NetBSD: Makefile,v 1.13 2021/05/30 08:04:48 markd Exp $

DISTNAME=	hyphen-slovenian
PKGNAME=	tex-${DISTNAME}-2021
TEXLIVE_REV=	58652

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Slovenian
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base

TEX_HYPHEN_DAT+=	slovenian loadhyph-sl.tex
TEX_HYPHEN_DAT+=	= slovene
TEX_HYPHEN_DEF+=	\\addlanguage{slovenian}{loadhyph-sl.tex}{}{2}{2}
TEX_HYPHEN_DEF+=	\\addlanguage{slovene}{loadhyph-sl.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['slovenian']={ \
			  loader='loadhyph-sl.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=2, \
			  synonyms={'slovene',}, \
			  patterns='hyph-sl.pat.txt', \
			  hyphenation='', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
