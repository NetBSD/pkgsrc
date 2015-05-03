# $NetBSD: Makefile,v 1.5 2015/05/03 17:52:39 wiz Exp $

DISTNAME=	hyphen-farsi
PKGNAME=	tex-${DISTNAME}-2010
PKGREVISION=	2
TEXLIVE_REV=	18673

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Farsi

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base

TEX_HYPHEN_DAT+=	farsi zerohyph.tex
TEX_HYPHEN_DAT+=	= persian
TEX_HYPHEN_DEF+=	\\addlanguage{farsi}{zerohyph.tex}{}{}{}
TEX_HYPHEN_DEF+=	\\addlanguage{persian}{zerohyph.tex}{}{}{}
TEX_HYPHEN_LUA+=	['farsi']={ \
			  loader='zerohyph.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=3, \
			  synonyms={'persian',}, \
			  patterns='', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
