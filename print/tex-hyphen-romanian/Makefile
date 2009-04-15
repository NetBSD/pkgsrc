# $NetBSD: Makefile,v 1.1.1.1 2009/04/15 07:46:32 minskim Exp $
# TeX Live Revision 9014

DISTNAME=	hyphen-romanian
PKGNAME=	tex-${DISTNAME}-2008.9014

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Romanian

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	romanian loadhyph-ro.tex
TEX_HYPHEN_DEF+=	\addlanguage{romanian}{loadhyph-ro.tex}{}{2}{2}

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
