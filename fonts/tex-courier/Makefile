# $NetBSD: Makefile,v 1.9 2016/01/30 04:56:41 markd Exp $

DISTNAME=	courier
PKGNAME=	tex-${DISTNAME}-2014
TEXLIVE_REV=	35058

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Adobe Type 1 "free" copies of Courier
LICENSE=	gnu-gpl-v2

CONFLICTS+=	teTeX-texmf<=3.0nb19

TEX_MAP_FILES+=	ucr.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
