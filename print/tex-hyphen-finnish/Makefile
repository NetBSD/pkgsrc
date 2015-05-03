# $NetBSD: Makefile,v 1.5 2015/05/03 17:52:39 wiz Exp $

DISTNAME=	hyphen-finnish
PKGNAME=	tex-${DISTNAME}-2010
PKGREVISION=	2
TEXLIVE_REV=	20144

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Finnish language

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	finnish loadhyph-fi.tex
TEX_HYPHEN_DEF+=	\\addlanguage{finnish}{loadhyph-fi.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['finnish']={ \
			  loader='loadhyph-fi.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=2, \
			  synonyms={}, \
			  patterns='hyph-fi.pat.txt', \
			  hyphenation='', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
