# $NetBSD: Makefile,v 1.5 2015/05/03 17:52:40 wiz Exp $

DISTNAME=	hyphen-italian
PKGNAME=	tex-${DISTNAME}-4.8g
PKGREVISION=	2
TEXLIVE_REV=	20144

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for the Italian language

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	italian loadhyph-it.tex
TEX_HYPHEN_DEF+=	\\addlanguage{italian}{loadhyph-it.tex}{}{2}{2}
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
