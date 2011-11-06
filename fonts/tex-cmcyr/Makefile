# $NetBSD: Makefile,v 1.3 2011/11/06 08:43:29 minskim Exp $

DISTNAME=	cmcyr
PKGNAME=	tex-${DISTNAME}-2009
PKGREVISION=	1
TEXLIVE_REV=	16696
DIST_SUBDIR=	${PKGBASE}-${TEXLIVE_REV}.2010

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Computer Modern fonts with cyrillic extensions

CONFLICTS+=	teTeX-texmf<=3.0nb24

TEX_MAP_FILES+=	cmcyr.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
