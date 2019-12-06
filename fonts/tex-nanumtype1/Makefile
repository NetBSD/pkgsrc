# $NetBSD: Makefile,v 1.3 2019/12/06 19:32:14 markd Exp $

DISTNAME=	nanumtype1
PKGNAME=	tex-${DISTNAME}-3.0
PKGREVISION=	1
CATEGORIES=	fonts
TEXLIVE_REV=	29558

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Type1 subfonts of Nanum Korean fonts
LICENSE=	ofl-v1.1

TEX_MAP_FILES+=	nanumfonts.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
