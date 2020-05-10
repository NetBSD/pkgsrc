# $NetBSD: Makefile,v 1.8 2020/05/10 04:31:39 markd Exp $

DISTNAME=	bookman
PKGNAME=	tex-${DISTNAME}-2014
PKGREVISION=	1
TEXLIVE_REV=	31835

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Bookman font
LICENSE=	gnu-gpl-v2

TEX_MAP_FILES+=	ubk.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
