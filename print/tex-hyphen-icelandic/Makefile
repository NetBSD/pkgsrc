# $NetBSD: Makefile,v 1.1.1.1 2009/04/15 07:39:01 minskim Exp $
# TeX Live Revision 9005

DISTNAME=	hyphen-icelandic
PKGNAME=	tex-${DISTNAME}-2008.9005

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Icelandic

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	icelandic loadhyph-is.tex
TEX_HYPHEN_DEF+=	\addlanguage{icelandic}{loadhyph-is.tex}{}{2}{2}

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
