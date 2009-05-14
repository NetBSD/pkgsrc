# $NetBSD: Makefile,v 1.2 2009/05/14 01:29:40 minskim Exp $
# TeX Live Revision 9400

DISTNAME=	hyphen-ancientgreek
PKGNAME=	tex-${DISTNAME}-2008.9400
PKGREVISION=	1

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for ancient Greek

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	ancientgreek loadhyph-grc.tex
TEX_HYPHEN_DAT+=	ibycus ibyhyph.tex
TEX_HYPHEN_DEF+=	\addlanguage{ancientgreek}{loadhyph-grc.tex}{}{1}{1}
TEX_HYPHEN_DEF+=	\addlanguage{ibycus}{ibyhyph.tex}{}{2}{2}
TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
