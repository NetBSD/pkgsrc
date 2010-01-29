# $NetBSD: Makefile,v 1.2 2010/01/29 08:42:56 minskim Exp $
# TeX Live Revision 12665

DISTNAME=	tipa
PKGNAME=	tex-${DISTNAME}-1.3
PKGREVISION=	1

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Fonts and macros for IPA phonetics characters

DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex

TEX_MIXEDMAP_FILES+=	tipa.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
