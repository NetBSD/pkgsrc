# $NetBSD: Makefile,v 1.1.1.1 2009/04/15 07:32:21 minskim Exp $
# TeX Live Revision 8995

DISTNAME=	hyphen-esperanto
PKGNAME=	tex-${DISTNAME}-2008.8995

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Esperanto

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	esperanto loadhyph-eo.tex
TEX_HYPHEN_DEF+=	\addlanguage{esperanto}{loadhyph-eo.tex}{}{2}{2}

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
