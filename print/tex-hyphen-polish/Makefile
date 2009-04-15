# $NetBSD: Makefile,v 1.1.1.1 2009/04/15 07:45:20 minskim Exp $
# TeX Live Revision 9103

DISTNAME=	hyphen-polish
PKGNAME=	tex-${DISTNAME}-2008.9103

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Polish

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	polish loadhyph-pl.tex
TEX_HYPHEN_DEF+=	\addlanguage{polish}{loadhyph-pl.tex}{}{2}{2}

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
