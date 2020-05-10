# $NetBSD: Makefile,v 1.4 2020/05/10 04:31:50 markd Exp $

DISTNAME=	nanumtype1
PKGNAME=	tex-${DISTNAME}-3.0
PKGREVISION=	2
CATEGORIES=	fonts
TEXLIVE_REV=	29558

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Type1 subfonts of Nanum Korean fonts
LICENSE=	ofl-v1.1

TEX_MAP_FILES+=	nanumfonts.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
