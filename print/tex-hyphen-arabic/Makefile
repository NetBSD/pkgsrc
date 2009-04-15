# $NetBSD: Makefile,v 1.1.1.1 2009/04/15 07:18:43 minskim Exp $
# TeX Live Revision 8935

DISTNAME=	hyphen-arabic
PKGNAME=	tex-${DISTNAME}-2008.8935

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Arabic

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base

TEX_HYPHEN_DAT+=	arabic zerohyph.tex
TEX_HYPHEN_DEF+=	\addlanguage{arabic}{zerohyph.tex}{}{}{}

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
