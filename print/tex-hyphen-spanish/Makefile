# $NetBSD: Makefile,v 1.3 2015/05/03 17:52:41 wiz Exp $

DISTNAME=	hyphen-spanish
PKGNAME=	tex-${DISTNAME}-4.5
PKGREVISION=	1

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Spanish

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	spanish loadhyph-es.tex
TEX_HYPHEN_DAT+=	= espanol
TEX_HYPHEN_DEF+=	\\addlanguage{spanish}{loadhyph-es.tex}{}{2}{2}
TEX_HYPHEN_DEF+=	\\addlanguage{espanol}{loadhyph-es.tex}{}{2}{2}

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
