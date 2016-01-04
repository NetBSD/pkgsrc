# $NetBSD: Makefile,v 1.3 2016/01/04 18:22:15 wiedi Exp $

DISTNAME=	osm2pgsql-0.88.1
PKGREVISION=	1
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=openstreetmap/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	wiedi@frubar.net
HOMEPAGE=	https://github.com/openstreetmap/osm2pgsql/
COMMENT=	OpenStreetMap data to PostgreSQL converter
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake autoconf aclocal automake
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-zlib=${BUILDLINK_PREFIX.zlib}
CONFIGURE_ARGS+=	--with-bzip2=${BUILDLINK_PREFIX.bzip2}
CONFIGURE_ARGS+=	--with-proj=${BUILDLINK_PREFIX.proj}
CONFIGURE_ARGS+=	--with-protobuf-c=${BUILDLINK_PREFIX.protobuf-c}
CONFIGURE_ARGS+=	--with-boost=${BUILDLINK_PREFIX.boost-libs}

.include "../../mk/bsd.prefs.mk"

pre-configure:
	cd ${WRKSRC} && aclocal && ./autogen.sh

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../geography/geos/buildlink3.mk"
.include "../../geography/proj/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/protobuf-c/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
