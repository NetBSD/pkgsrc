# $NetBSD: Makefile,v 1.14 2026/03/26 08:07:42 markd Exp $

DISTNAME=	hyphen-estonian
PKGNAME=	tex-${DISTNAME}-2026
TEXLIVE_REV=	78069

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
