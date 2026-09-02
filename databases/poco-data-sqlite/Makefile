# $NetBSD: Makefile,v 1.47 2026/09/02 19:01:18 wiz Exp $

PKGNAME=	poco-data-sqlite-${POCO_VERSION}
PKGREVISION=	1
CATEGORIES=	databases

COMMENT=	POCO C++ SQLite RDBMS Accessor libraries

.include "../../devel/poco/Makefile.common"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_DATA_SQLITE=ON
CMAKE_CONFIGURE_ARGS+=	-DENABLE_FOUNDATION=OFF

.include "../../databases/poco-data/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
