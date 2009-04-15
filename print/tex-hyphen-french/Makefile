# $NetBSD: Makefile,v 1.1.1.1 2009/04/15 07:35:50 minskim Exp $
# TeX Live Revision 11021

DISTNAME=	hyphen-french
PKGNAME=	tex-${DISTNAME}-2008.11021

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for French

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	french loadhyph-fr.tex
TEX_HYPHEN_DAT+=	= patois
TEX_HYPHEN_DAT+=	= francais
TEX_HYPHEN_DEF+=	\addlanguage{french}{loadhyph-fr.tex}{}{2}{3}
TEX_HYPHEN_DEF+=	\addlanguage{patois}{loadhyph-fr.tex}{}{2}{3}
TEX_HYPHEN_DEF+=	\addlanguage{francais}{loadhyph-fr.tex}{}{2}{3}

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
