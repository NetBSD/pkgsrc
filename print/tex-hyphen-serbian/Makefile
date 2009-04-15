# $NetBSD: Makefile,v 1.1.1.1 2009/04/15 07:48:25 minskim Exp $
# TeX Live Revision 9371

DISTNAME=	hyphen-serbian
PKGNAME=	tex-${DISTNAME}-2008.9371

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Serbian

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	serbian loadhyph-sr-latn.tex
TEX_HYPHEN_DEF+=	\addlanguage{serbian}{loadhyph-sr-latn.tex}{}{2}{2}

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
