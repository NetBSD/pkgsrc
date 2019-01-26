# $NetBSD: Makefile,v 1.8 2019/01/26 23:24:05 markd Exp $

DISTNAME=	hyphen-basque
PKGNAME=	tex-${DISTNAME}-2018
TEXLIVE_REV=	49078

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation for Basque
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	basque loadhyph-eu.tex
TEX_HYPHEN_DEF+=	\\addlanguage{basque}{loadhyph-eu.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['basque']={ \
			  loader='loadhyph-eu.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=2, \
			  synonyms={}, \
			  patterns='hyph-eu.pat.txt', \
			  hyphenation='', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
