# $NetBSD: Makefile,v 1.2 2010/05/24 06:08:36 minskim Exp $

DISTNAME=	hyphen-slovak
PKGNAME=	tex-${DISTNAME}-2009
TEXLIVE_REV=	13822

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Slovak

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	slovak loadhyph-sk.tex
TEX_HYPHEN_DEF+=	\addlanguage{slovak}{loadhyph-sk.tex}{}{2}{3}

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
