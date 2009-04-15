# $NetBSD: Makefile,v 1.1.1.1 2009/04/15 07:49:07 minskim Exp $
# TeX Live Revision 9031

DISTNAME=	hyphen-slovak
PKGNAME=	tex-${DISTNAME}-2008.9031

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Slovak

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	slovak loadhyph-sk.tex
TEX_HYPHEN_DEF+=	\addlanguage{slovak}{loadhyph-sk.tex}{}{2}{3}

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
