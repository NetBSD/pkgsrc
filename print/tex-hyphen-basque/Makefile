# $NetBSD: Makefile,v 1.4 2010/11/10 17:55:28 minskim Exp $

DISTNAME=	hyphen-basque
PKGNAME=	tex-${DISTNAME}-2010
PKGREVISION=	1
TEXLIVE_REV=	20144

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation for Basque

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	basque loadhyph-eu.tex
TEX_HYPHEN_DEF+=	\addlanguage{basque}{loadhyph-eu.tex}{}{2}{2}
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
