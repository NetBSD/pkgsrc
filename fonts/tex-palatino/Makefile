# $NetBSD: Makefile,v 1.8 2020/05/10 04:31:51 markd Exp $

DISTNAME=	palatino
PKGNAME=	tex-${DISTNAME}-2014
PKGREVISION=	1
TEXLIVE_REV=	31835

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Palatino font family for TeX
LICENSE=	lppl-1.3c

TEX_MAP_FILES+=	upl.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
