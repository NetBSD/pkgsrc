# $NetBSD: Makefile,v 1.1.1.1 2009/04/15 07:40:41 minskim Exp $
# TeX Live Revision 9004

DISTNAME=	hyphen-interlingua
PKGNAME=	tex-${DISTNAME}-2008.9004

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Interlingua

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	interlingua loadhyph-ia.tex
TEX_HYPHEN_DEF+=	\addlanguage{interlingua}{loadhyph-ia.tex}{}{2}{2}

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
