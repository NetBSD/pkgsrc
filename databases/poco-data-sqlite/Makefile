# $NetBSD: Makefile,v 1.46 2026/07/24 12:15:54 adam Exp $

PKGNAME=	poco-data-sqlite-${POCO_VERSION}
CATEGORIES=	databases

COMMENT=	POCO C++ SQLite RDBMS Accessor libraries

.include "../../devel/poco/Makefile.common"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_DATA_SQLITE=ON
CMAKE_CONFIGURE_ARGS+=	-DENABLE_FOUNDATION=OFF

.include "../../databases/poco-data/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
