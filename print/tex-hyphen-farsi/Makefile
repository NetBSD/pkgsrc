# $NetBSD: Makefile,v 1.6 2015/05/05 12:18:29 markd Exp $

DISTNAME=	hyphen-farsi
PKGNAME=	tex-${DISTNAME}-2010
PKGREVISION=	3
TEXLIVE_REV=	18673

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Farsi

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base

TEX_HYPHEN_DAT+=	farsi zerohyph.tex
TEX_HYPHEN_DAT+=	= persian
TEX_HYPHEN_DEF+=	\\addlanguage{farsi}{zerohyph.tex}{}{0}{0}
TEX_HYPHEN_DEF+=	\\addlanguage{persian}{zerohyph.tex}{}{0}{0}
TEX_HYPHEN_LUA+=	['farsi']={ \
			  loader='zerohyph.tex', \
			  lefthyphenmin=0, \
			  righthyphenmin=0, \
			  synonyms={'persian',}, \
			  patterns='', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
