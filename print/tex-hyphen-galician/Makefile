# $NetBSD: Makefile,v 1.1.1.1 2009/04/15 07:36:23 minskim Exp $
# TeX Live Revision 8999

DISTNAME=	hyphen-galician
PKGNAME=	tex-${DISTNAME}-2008.8999

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Galician

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	galician loadhyph-gl.tex
TEX_HYPHEN_DEF+=	\addlanguage{galician}{loadhyph-gl.tex}{}{2}{2}

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
