# $NetBSD: Makefile,v 1.1 2026/07/24 12:15:54 adam Exp $

PKGNAME=	poco-data-postgresql-${POCO_VERSION}
CATEGORIES=	databases

COMMENT=	POCO C++ PostgreSQL RDBMS Accessor libraries

.include "../../devel/poco/Makefile.common"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_DATA_POSTGRESQL=ON
CMAKE_CONFIGURE_ARGS+=	-DENABLE_FOUNDATION=OFF

.include "../../databases/poco-data/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
