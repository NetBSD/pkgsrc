# $NetBSD: Makefile,v 1.1.1.1 2009/04/15 07:41:43 minskim Exp $
# TeX Live Revision 8973

DISTNAME=	hyphen-irish
PKGNAME=	tex-${DISTNAME}-2008.8973

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Irish

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	irish loadhyph-ga.tex
TEX_HYPHEN_DEF+=	\addlanguage{irish}{loadhyph-ga.tex}{}{2}{3}

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
