# $NetBSD: Makefile,v 1.1.1.1 2009/04/15 07:51:34 minskim Exp $
# TeX Live Revision 9019

DISTNAME=	hyphen-turkish
PKGNAME=	tex-${DISTNAME}-2008.9019

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Turkish

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	turkish loadhyph-tr.tex
TEX_HYPHEN_DEF+=	\addlanguage{turkish}{loadhyph-tr.tex}{}{2}{2}

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
