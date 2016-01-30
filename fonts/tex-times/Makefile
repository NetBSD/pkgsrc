# $NetBSD: Makefile,v 1.8 2016/01/30 04:56:44 markd Exp $

DISTNAME=	times
PKGNAME=	tex-${DISTNAME}-2014
TEXLIVE_REV=	35058

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Select Adobe Times Roman (or equivalent) as default font
LICENSE=	gnu-gpl-v2

CONFLICTS+=	teTeX-texmf<=3.0nb16

TEX_MAP_FILES+=	utm.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
