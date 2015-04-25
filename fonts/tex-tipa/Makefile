# $NetBSD: Makefile,v 1.5 2015/04/25 08:33:07 markd Exp $

DISTNAME=	tipa
PKGNAME=	tex-${DISTNAME}-1.3pl29349
TEXLIVE_REV=	29349

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Fonts and macros for IPA phonetics characters

DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex

TEX_MIXEDMAP_FILES+=	tipa.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
