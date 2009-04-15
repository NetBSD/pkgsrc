# $NetBSD: Makefile,v 1.1.1.1 2009/04/15 07:55:07 minskim Exp $
# TeX Live Revision 8985

DISTNAME=	hyphen-welsh
PKGNAME=	tex-${DISTNAME}-2008.8985

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Welsh

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	welsh loadhyph-cy.tex
TEX_HYPHEN_DEF+=	\addlanguage{welsh}{loadhyph-cy.tex}{}{2}{3}

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
