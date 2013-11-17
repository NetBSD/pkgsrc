# $NetBSD: Makefile,v 1.4 2013/11/17 17:22:05 minskim Exp $

DISTNAME=	hyphen-german
PKGNAME=	tex-${DISTNAME}-2013
TEXLIVE_REV=	29725

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for German

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	german loadhyph-de-1901.tex
TEX_HYPHEN_DAT+=	ngerman loadhyph-de-1996.tex
TEX_HYPHEN_DEF+=	\addlanguage{german}{loadhyph-de-1901.tex}{}{2}{2}
TEX_HYPHEN_DEF+=	\addlanguage{ngerman}{loadhyph-de-1996.tex}{}{2}{2}

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
