# $NetBSD: Makefile,v 1.1.1.1 2009/04/15 07:47:52 minskim Exp $
# TeX Live Revision 9090

DISTNAME=	hyphen-sanskrit
PKGNAME=	tex-${DISTNAME}-2008.9090

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Sanskrit

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	sanskrit loadhyph-sa.tex
TEX_HYPHEN_DEF+=	\addlanguage{sanskrit}{loadhyph-sa.tex}{}{1}{5}

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
