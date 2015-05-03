# $NetBSD: Makefile,v 1.5 2015/05/03 17:52:40 wiz Exp $

DISTNAME=	hyphen-german
PKGNAME=	tex-${DISTNAME}-2013
PKGREVISION=	1
TEXLIVE_REV=	29725

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for German

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	german loadhyph-de-1901.tex
TEX_HYPHEN_DAT+=	ngerman loadhyph-de-1996.tex
TEX_HYPHEN_DEF+=	\\addlanguage{german}{loadhyph-de-1901.tex}{}{2}{2}
TEX_HYPHEN_DEF+=	\\addlanguage{ngerman}{loadhyph-de-1996.tex}{}{2}{2}

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
