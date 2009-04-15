# $NetBSD: Makefile,v 1.1.1.1 2009/04/15 07:39:43 minskim Exp $
# TeX Live Revision 9006

DISTNAME=	hyphen-indonesian
PKGNAME=	tex-${DISTNAME}-2008.9006

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Indonesian

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	indonesian loadhyph-id.tex
TEX_HYPHEN_DEF+=	\addlanguage{indonesian}{loadhyph-id.tex}{}{2}{2}

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
