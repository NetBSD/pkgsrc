# $NetBSD: Makefile,v 1.11 2020/05/10 04:31:55 markd Exp $

DISTNAME=	times
PKGNAME=	tex-${DISTNAME}-2014
PKGREVISION=	1
TEXLIVE_REV=	35058

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Select Adobe Times Roman (or equivalent) as default font
LICENSE=	gnu-gpl-v2

TEX_MAP_FILES+=	utm.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
