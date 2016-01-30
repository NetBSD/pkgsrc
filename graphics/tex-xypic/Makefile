# $NetBSD: Makefile,v 1.4 2016/01/30 04:05:54 markd Exp $

DISTNAME=	xypic
PKGNAME=	tex-${DISTNAME}-3.8.9
TEXLIVE_REV=	31859

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Flexible diagramming macros
LICENSE=	gnu-gpl-v2

CONFLICTS=	teTeX-texmf<=3.0nb29

TEX_MIXEDMAP_FILES+=	xypic.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
