# $NetBSD: Makefile,v 1.4 2010/11/10 17:55:32 minskim Exp $

DISTNAME=	hyphen-italian
PKGNAME=	tex-${DISTNAME}-4.8g
PKGREVISION=	1
TEXLIVE_REV=	20144

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for the Italian language

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	italian loadhyph-it.tex
TEX_HYPHEN_DEF+=	\addlanguage{italian}{loadhyph-it.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['italian']={ \
			  loader='loadhyph-it.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=2, \
			  synonyms={}, \
			  patterns='hyph-it.pat.txt', \
			  hyphenation='', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
