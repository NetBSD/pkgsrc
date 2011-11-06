# $NetBSD: Makefile,v 1.4 2011/11/06 08:43:31 minskim Exp $

DISTNAME=	manfnt
PKGNAME=	tex-${DISTNAME}-2009
PKGREVISION=	1
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	LaTeX support for the TeX book symbols

CONFLICTS+=	teTeX-texmf<=3.0nb15

TEX_MIXEDMAP_FILES+=	manfnt.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
