# $NetBSD: Makefile,v 1.7 2013/12/03 22:33:45 minskim Exp $

DISTNAME=	lm
PKGNAME=	tex-${DISTNAME}-2.004
PKGREVISION=	2
TEXLIVE_REV=	28119

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Latin modern fonts in outline formats

CONFLICTS+=	teTeX-texmf<=3.0nb16

TEX_MAP_FILES+=	lm.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
