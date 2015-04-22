# $NetBSD: Makefile,v 1.3 2015/04/22 00:16:44 markd Exp $

DISTNAME=	xypic
PKGNAME=	tex-${DISTNAME}-3.8.9
TEXLIVE_REV=	31859

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Flexible diagramming macros

CONFLICTS=	teTeX-texmf<=3.0nb29

TEX_MIXEDMAP_FILES+=	xypic.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
