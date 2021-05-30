# $NetBSD: Makefile,v 1.12 2021/05/30 08:04:44 markd Exp $

DISTNAME=	hyphen-estonian
PKGNAME=	tex-${DISTNAME}-2021
TEXLIVE_REV=	58652

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Estonian
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base

TEX_HYPHEN_DAT+=	estonian loadhyph-et.tex
TEX_HYPHEN_DEF+=	\\addlanguage{estonian}{loadhyph-et.tex}{}{2}{3}
TEX_HYPHEN_LUA+=	['estonian']={ \
			  loader='loadhyph-et.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=3, \
			  synonyms={}, \
			  patterns='hyph-et.pat.txt', \
			  hyphenation='', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
