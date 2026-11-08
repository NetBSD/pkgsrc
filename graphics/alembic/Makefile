# $NetBSD: Makefile,v 1.1 2026/11/08 14:57:45 ryoon Exp $

DISTNAME=	alembic-1.8.12
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=alembic/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://www.alembic.io/
COMMENT=	Open framework for storing and sharing scene data
LICENSE=	modified-bsd

USE_LANGUAGES+=	c c++

.include "../../devel/cmake/build.mk"
.include "../../math/imath/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
