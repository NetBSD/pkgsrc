# $NetBSD: Makefile,v 1.2 2010/09/13 05:29:31 minskim Exp $

DISTNAME=	cmcyr
PKGNAME=	tex-${DISTNAME}-2009
TEXLIVE_REV=	16696
DIST_SUBDIR=	${PKGBASE}-${TEXLIVE_REV}.2010

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Computer Modern fonts with cyrillic extensions

CONFLICTS+=	teTeX-texmf<=3.0nb24

TEX_MAP_FILES+=	cmcyr.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
