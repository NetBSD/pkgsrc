# $NetBSD: Makefile,v 1.2 2011/11/06 08:43:32 minskim Exp $

DISTNAME=	xypic
PKGNAME=	tex-${DISTNAME}-3.8.5
PKGREVISION=	1
TEXLIVE_REV=	21380

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Flexible diagramming macros

CONFLICTS=	teTeX-texmf<=3.0nb29

TEX_MIXEDMAP_FILES+=	xypic.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
