# $NetBSD: Makefile,v 1.1.1.1 2009/04/29 18:37:26 minskim Exp $
# TeX Live Revision 12665

DISTNAME=	tipa
PKGNAME=	tex-${DISTNAME}-1.3

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Fonts and macros for IPA phonetics characters

DEPENDS+=	tex-bin-latex-[0-9]*:../../print/tex-bin-latex
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex

TEX_MIXEDMAP_FILES+=	tipa.map

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
