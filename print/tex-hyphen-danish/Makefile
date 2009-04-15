# $NetBSD: Makefile,v 1.1.1.1 2009/04/15 07:30:38 minskim Exp $
# TeX Live Revision 9091

DISTNAME=	hyphen-danish
PKGNAME=	tex-${DISTNAME}-2008.9091

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Danish

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	danish loadhyph-da.tex
TEX_HYPHEN_DEF+=	\addlanguage{danish}{loadhyph-da.tex}{}{2}{2}

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
