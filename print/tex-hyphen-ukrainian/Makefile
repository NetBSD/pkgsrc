# $NetBSD: Makefile,v 1.1.1.1 2009/04/15 07:53:19 minskim Exp $
# TeX Live Revision 9370

DISTNAME=	hyphen-ukrainian
PKGNAME=	tex-${DISTNAME}-2008.9370

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Ukrainian

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8
DEPENDS+=	tex-ukrhyph-[0-9]*:../../print/tex-ukrhyph

TEX_HYPHEN_DAT+=	ukrainian loadhyph-uk.tex
TEX_HYPHEN_DEF+=	\addlanguage{ukrainian}{loadhyph-uk.tex}{}{2}{2}

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
