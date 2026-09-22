# $NetBSD: Makefile,v 1.1 2026/09/22 08:20:33 ryoon Exp $

DISTNAME=	quickjs-0.16.2
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
