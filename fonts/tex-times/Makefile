# $NetBSD: Makefile,v 1.10 2019/12/06 19:32:28 markd Exp $

DISTNAME=	times
PKGNAME=	tex-${DISTNAME}-2014
TEXLIVE_REV=	35058

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Select Adobe Times Roman (or equivalent) as default font
LICENSE=	gnu-gpl-v2

TEX_MAP_FILES+=	utm.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
