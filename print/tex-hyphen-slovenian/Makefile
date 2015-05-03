# $NetBSD: Makefile,v 1.5 2015/05/03 17:52:41 wiz Exp $

DISTNAME=	hyphen-slovenian
PKGNAME=	tex-${DISTNAME}-2010
PKGREVISION=	2
TEXLIVE_REV=	20144

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Slovenian

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

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
