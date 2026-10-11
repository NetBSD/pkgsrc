# $NetBSD: Makefile,v 1.2 2026/10/11 16:35:33 wiz Exp $

DISTNAME=	quickjs-0.17.0
PKGNAME=	${DISTNAME:S/quickjs-/quickjs-ng-/}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=quickjs-ng/}
GITHUB_PROJECT=	quickjs
GITHUB_TAG=	v${PKGVERSION_NOREV}
DIST_SUBDIR=	${PKGNAME_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/quickjs-ng/quickjs/
COMMENT=	Fork of QuickJS
LICENSE=	mit

CONFLICTS+=	quickjs-[0-9]*

USE_LANGUAGES=	c c++

.include "../../devel/cmake/build.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
