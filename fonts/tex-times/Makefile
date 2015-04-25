# $NetBSD: Makefile,v 1.7 2015/04/25 08:30:26 markd Exp $

DISTNAME=	times
PKGNAME=	tex-${DISTNAME}-2014
TEXLIVE_REV=	35058

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Select Adobe Times Roman (or equivalent) as default font

CONFLICTS+=	teTeX-texmf<=3.0nb16

TEX_MAP_FILES+=	utm.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
