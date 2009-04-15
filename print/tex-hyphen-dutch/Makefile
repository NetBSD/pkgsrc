# $NetBSD: Makefile,v 1.1.1.1 2009/04/15 07:31:42 minskim Exp $
# TeX Live Revision 9010

DISTNAME=	hyphen-dutch
PKGNAME=	tex-${DISTNAME}-2008.9010

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Dutch

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	dutch loadhyph-nl.tex
TEX_HYPHEN_DEF+=	\addlanguage{dutch}{loadhyph-nl.tex}{}{2}{2}

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
