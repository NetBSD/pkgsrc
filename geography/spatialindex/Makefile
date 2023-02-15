# $NetBSD: Makefile,v 1.2 2023/02/15 23:17:32 wiz Exp $

DISTNAME=	spatialindex-src-1.9.3
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=libspatialindex/}
GITHUB_PROJECT=	libspatialindex
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://libspatialindex.github.io/
COMMENT=	Robust spatial indexing methods
LICENSE=	mit

USE_LANGUAGES=		c c++

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
