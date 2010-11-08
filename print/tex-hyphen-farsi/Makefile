# $NetBSD: Makefile,v 1.3 2010/11/08 00:36:37 minskim Exp $

DISTNAME=	hyphen-farsi
PKGNAME=	tex-${DISTNAME}-2010
TEXLIVE_REV=	18673

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Farsi

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base

TEX_HYPHEN_DAT+=	farsi zerohyph.tex
TEX_HYPHEN_DAT+=	= persian
TEX_HYPHEN_DEF+=	\addlanguage{farsi}{zerohyph.tex}{}{}{}
TEX_HYPHEN_DEF+=	\addlanguage{persian}{zerohyph.tex}{}{}{}
TEX_HYPHEN_LUA+=	['farsi']={ \
			\\tloader='zerohyph.tex', \
			\\tlefthyphenmin=2, \
			\\trighthyphenmin=3, \
			\\tsynonyms={'persian',}, \
			\\tpatterns='', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
