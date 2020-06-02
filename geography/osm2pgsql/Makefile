# $NetBSD: Makefile,v 1.25 2020/06/02 08:23:58 adam Exp $

DISTNAME=	osm2pgsql-1.2.1
PKGREVISION=	3
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=openstreetmap/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	wiedi@frubar.net
HOMEPAGE=	https://github.com/openstreetmap/osm2pgsql/
COMMENT=	OpenStreetMap data to PostgreSQL converter
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/osm2pgsql-${PKGVERSION_NOREV}
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

# osm2pgsql does not allow srcdir builds (and separate is better anyway)
post-extract:
	${RUN} mkdir -p ${WRKSRC}/build
CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	${WRKSRC}

.include "../../geography/proj/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
