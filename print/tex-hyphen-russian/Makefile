# $NetBSD: Makefile,v 1.1.1.1 2009/04/15 07:47:19 minskim Exp $
# TeX Live Revision 8935

DISTNAME=	hyphen-russian
PKGNAME=	tex-${DISTNAME}-2008.8935

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Russian

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8
DEPENDS+=	tex-ruhyphen-[0-9]*:../../print/tex-ruhyphen

TEX_HYPHEN_DAT+=	russian loadhyph-ru.tex
TEX_HYPHEN_DEF+=	\addlanguage{russian}{loadhyph-ru.tex}{}{2}{2}

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
