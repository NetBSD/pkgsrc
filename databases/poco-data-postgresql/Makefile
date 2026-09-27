# $NetBSD: Makefile,v 1.3 2026/09/27 11:35:23 tnn Exp $

PKGNAME=	poco-data-postgresql-${POCO_VERSION}
PKGREVISION=	2
CATEGORIES=	databases

COMMENT=	POCO C++ PostgreSQL RDBMS Accessor libraries

.include "../../devel/poco/Makefile.common"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_DATA_POSTGRESQL=ON
CMAKE_CONFIGURE_ARGS+=	-DENABLE_FOUNDATION=OFF

.include "../../databases/poco-data/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
