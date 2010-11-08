# $NetBSD: Makefile,v 1.3 2010/11/08 00:31:33 minskim Exp $

DISTNAME=	hyphen-arabic
PKGNAME=	tex-${DISTNAME}-2010
TEXLIVE_REV=	18673

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Arabic

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base

TEX_HYPHEN_DAT+=	arabic zerohyph.tex
TEX_HYPHEN_DEF+=	\addlanguage{arabic}{zerohyph.tex}{}{}{}
TEX_HYPHEN_LUA+=	['arabic']={ \
			\\tloader='zerohyph.tex', \
			\\tlefthyphenmin=2, \
			\\trighthyphenmin=3, \
			\\tsynonyms={}, \
			\\tpatterns='', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
