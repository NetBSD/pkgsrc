# $NetBSD: Makefile,v 1.1.1.1 2009/04/15 07:34:37 minskim Exp $
# TeX Live Revision 8935

DISTNAME=	hyphen-farsi
PKGNAME=	tex-${DISTNAME}-2008.8935

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Farsi

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base

TEX_HYPHEN_DAT+=	farsi zerohyph.tex
TEX_HYPHEN_DAT+=	= persian
TEX_HYPHEN_DEF+=	\addlanguage{farsi}{zerohyph.tex}{}{}{}
TEX_HYPHEN_DEF+=	\addlanguage{persian}{zerohyph.tex}{}{}{}

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
