# $NetBSD: Makefile,v 1.5 2016/01/30 04:56:44 markd Exp $

DISTNAME=	txfonts
PKGNAME=	tex-${DISTNAME}-2009
PKGREVISION=	1
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Times-like fonts in support of mathematics
LICENSE=	gnu-gpl-v2

CONFLICTS+=	teTeX-texmf<=3.0nb19

TEX_MAP_FILES+=	txfonts.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
