# $NetBSD: Makefile,v 1.1.1.1 2009/04/15 07:35:09 minskim Exp $
# TeX Live Revision 8998

DISTNAME=	hyphen-finnish
PKGNAME=	tex-${DISTNAME}-2008.8998

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Finnish

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	finnish loadhyph-fi.tex
TEX_HYPHEN_DEF+=	\addlanguage{finnish}{loadhyph-fi.tex}{}{2}{2}

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
