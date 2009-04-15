# $NetBSD: Makefile,v 1.1.1.1 2009/04/15 07:45:50 minskim Exp $
# TeX Live Revision 9012

DISTNAME=	hyphen-portuguese
PKGNAME=	tex-${DISTNAME}-2008.9012

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Portuguese

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	portuguese loadhyph-pt.tex
TEX_HYPHEN_DAT+=	= portuges
TEX_HYPHEN_DEF+=	\addlanguage{portuguese}{loadhyph-pt.tex}{}{2}{3}
TEX_HYPHEN_DEF+=	\addlanguage{portuges}{loadhyph-pt.tex}{}{2}{3}

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
