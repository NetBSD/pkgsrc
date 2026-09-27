# $NetBSD: Makefile,v 1.48 2026/09/27 11:35:23 tnn Exp $

PKGNAME=	poco-data-sqlite-${POCO_VERSION}
PKGREVISION=	2
CATEGORIES=	databases

COMMENT=	POCO C++ SQLite RDBMS Accessor libraries

.include "../../devel/poco/Makefile.common"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_DATA_SQLITE=ON
CMAKE_CONFIGURE_ARGS+=	-DENABLE_FOUNDATION=OFF

.include "../../databases/poco-data/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
