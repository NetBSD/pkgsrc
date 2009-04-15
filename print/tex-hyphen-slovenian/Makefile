# $NetBSD: Makefile,v 1.1.1.1 2009/04/15 07:49:59 minskim Exp $
# TeX Live Revision 9015

DISTNAME=	hyphen-slovenian
PKGNAME=	tex-${DISTNAME}-2008.9015

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Slovenian

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	slovenian loadhyph-sl.tex
TEX_HYPHEN_DAT+=	= slovene
TEX_HYPHEN_DEF+=	\addlanguage{slovenian}{loadhyph-sl.tex}{}{2}{2}
TEX_HYPHEN_DEF+=	\addlanguage{slovene}{loadhyph-sl.tex}{}{2}{2}

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
