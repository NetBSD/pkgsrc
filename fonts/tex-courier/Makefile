# $NetBSD: Makefile,v 1.8 2015/04/25 07:53:38 markd Exp $

DISTNAME=	courier
PKGNAME=	tex-${DISTNAME}-2014
TEXLIVE_REV=	35058

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Adobe Type 1 "free" copies of Courier

CONFLICTS+=	teTeX-texmf<=3.0nb19

TEX_MAP_FILES+=	ucr.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
