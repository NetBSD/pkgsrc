# $NetBSD: Makefile,v 1.2 2010/05/24 06:08:33 minskim Exp $

DISTNAME=	hyphen-arabic
PKGNAME=	tex-${DISTNAME}-2009
TEXLIVE_REV=	13822

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Arabic

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base

TEX_HYPHEN_DAT+=	arabic zerohyph.tex
TEX_HYPHEN_DEF+=	\addlanguage{arabic}{zerohyph.tex}{}{}{}

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
