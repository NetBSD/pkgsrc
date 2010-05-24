# $NetBSD: Makefile,v 1.2 2010/05/24 06:08:36 minskim Exp $

DISTNAME=	hyphen-mongolian
PKGNAME=	tex-${DISTNAME}-2009
TEXLIVE_REV=	17773

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Mongolian

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	mongolian loadhyph-mn-cyrl.tex
TEX_HYPHEN_DAT+=	mongolian2a loadhyph-mn-cyrl-x-lmc.tex
TEX_HYPHEN_DEF+=	\addlanguage{mongolian}{loadhyph-mn-cyrl.tex}{}{2}{2}
TEX_HYPHEN_DEF+=	\addlanguage{mongolian2a}{loadhyph-mn-cyrl-x-lmc.tex}{}{2}{2}

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
