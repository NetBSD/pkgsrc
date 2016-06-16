# $NetBSD: Makefile,v 1.5 2016/06/16 03:57:27 markd Exp $

DISTNAME=	cmcyr
PKGNAME=	tex-${DISTNAME}-2016
TEXLIVE_REV=	39273

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Computer Modern fonts with cyrillic extensions
LICENSE=	public-domain

CONFLICTS+=	teTeX-texmf<=3.0nb24

TEX_MAP_FILES+=	cmcyr.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
