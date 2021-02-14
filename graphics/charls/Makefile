# $NetBSD: Makefile,v 1.1 2021/02/14 11:51:57 nros Exp $

GITHUB_PROJECT=	charls
GITHUB_TAG=	2.2.0
DISTNAME=	2.2.0
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=team-charls/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/team-charls/charls/
COMMENT=	Jpeg-ls codec library
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/charls-2.2.0
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS:BOOL=ON
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release

PKGCONFIG_OVERRIDE=	src/charls-template.pc

.include "../../mk/bsd.pkg.mk"
