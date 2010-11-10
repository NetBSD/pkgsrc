# $NetBSD: Makefile,v 1.4 2010/11/10 17:55:30 minskim Exp $

DISTNAME=	hyphen-estonian
PKGNAME=	tex-${DISTNAME}-2010
PKGREVISION=	1
TEXLIVE_REV=	20144

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Estonian

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	estonian loadhyph-et.tex
TEX_HYPHEN_DEF+=	\addlanguage{estonian}{loadhyph-et.tex}{}{2}{3}
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
