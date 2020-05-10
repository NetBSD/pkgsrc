# $NetBSD: Makefile,v 1.9 2020/05/10 04:31:54 markd Exp $

DISTNAME=	symbol
PKGNAME=	tex-${DISTNAME}-2014
PKGREVISION=	1
TEXLIVE_REV=	31835

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Symbol fonts for TeX
LICENSE=	lppl-1.3c

TEX_MAP_FILES+=	usy.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
