# $NetBSD: Makefile,v 1.1 2026/09/24 16:12:48 ktnb Exp $

DISTNAME=	miniz-3.1.2
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=richgel999/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/richgel999/miniz/
COMMENT=	Single C source file zlib-replacement library
LICENSE=	mit

USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	miniz.pc.in

.include "../../devel/cmake/build.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
