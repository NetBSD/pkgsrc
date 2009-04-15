# $NetBSD: Makefile,v 1.1.1.1 2009/04/15 07:29:53 minskim Exp $
# TeX Live Revision 9030

DISTNAME=	hyphen-czech
PKGNAME=	tex-${DISTNAME}-2008.9030

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Czech

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	czech loadhyph-cs.tex
TEX_HYPHEN_DEF+=	\addlanguage{czech}{loadhyph-cs.tex}{}{2}{3}

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
