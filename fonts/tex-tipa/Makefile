# $NetBSD: Makefile,v 1.4 2011/11/06 08:43:32 minskim Exp $
# TeX Live Revision 15878

DISTNAME=	tipa
PKGNAME=	tex-${DISTNAME}-1.3
PKGREVISION=	2

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Fonts and macros for IPA phonetics characters

DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex

TEX_MIXEDMAP_FILES+=	tipa.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
