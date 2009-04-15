# $NetBSD: Makefile,v 1.1.1.1 2009/04/15 07:28:05 minskim Exp $
# TeX Live Revision 8935

DISTNAME=	hyphen-coptic
PKGNAME=	tex-${DISTNAME}-2008.8935

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Coptic

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	coptic loadhyph-cop.tex
TEX_HYPHEN_DEF+=	\addlanguage{coptic}{loadhyph-cop.tex}{}{1}{1}

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
