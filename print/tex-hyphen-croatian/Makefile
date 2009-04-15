# $NetBSD: Makefile,v 1.1.1.1 2009/04/15 07:28:48 minskim Exp $
# TeX Live Revision 9002

DISTNAME=	hyphen-croatian
PKGNAME=	tex-${DISTNAME}-2008.9002

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Croatian

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	croatian loadhyph-hr.tex
TEX_HYPHEN_DEF+=	\addlanguage{croatian}{loadhyph-hr.tex}{}{2}{2}

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
