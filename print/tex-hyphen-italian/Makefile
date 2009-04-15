# $NetBSD: Makefile,v 1.1.1.1 2009/04/15 07:42:13 minskim Exp $
# TeX Live Revision 9007

DISTNAME=	hyphen-italian
PKGNAME=	tex-${DISTNAME}-2008.9007

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Italian

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	italian loadhyph-it.tex
TEX_HYPHEN_DEF+=	\addlanguage{italian}{loadhyph-it.tex}{}{2}{2}

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
