# $NetBSD: Makefile,v 1.8 2016/01/30 04:56:43 markd Exp $

DISTNAME=	lm
PKGNAME=	tex-${DISTNAME}-2.004
PKGREVISION=	2
TEXLIVE_REV=	28119

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Latin modern fonts in outline formats
LICENSE=	gfsl

CONFLICTS+=	teTeX-texmf<=3.0nb16

TEX_MAP_FILES+=	lm.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
