# $NetBSD: Makefile,v 1.1.1.1 2009/04/15 07:20:57 minskim Exp $
# TeX Live Revision 8983

DISTNAME=	hyphen-basque
PKGNAME=	tex-${DISTNAME}-2008.8983

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Basque

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	basque loadhyph-eu.tex
TEX_HYPHEN_DEF+=	\addlanguage{basque}{loadhyph-eu.tex}{}{2}{2}

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
