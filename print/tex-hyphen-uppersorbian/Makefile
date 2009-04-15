# $NetBSD: Makefile,v 1.2 2009/04/15 07:56:01 minskim Exp $
# TeX Live Revision 9017

DISTNAME=	hyphen-uppersorbian
PKGNAME=	tex-${DISTNAME}-2008.9017

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Upper Sorbian

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	uppersorbian loadhyph-hsb.tex
TEX_HYPHEN_DEF+=	\addlanguage{uppersorbian}{loadhyph-hsb.tex}{}{2}{2}

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
