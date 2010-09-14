# $NetBSD: Makefile,v 1.3 2010/09/14 00:24:39 minskim Exp $

DISTNAME=	txfonts
PKGNAME=	tex-${DISTNAME}-2009
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Times-like fonts in support of mathematics

CONFLICTS+=	teTeX-texmf<=3.0nb19

TEX_MAP_FILES+=	txfonts.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
