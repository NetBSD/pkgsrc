# $NetBSD: Makefile,v 1.14 2026/07/24 12:15:54 adam Exp $

PKGNAME=	poco-data-odbc-${POCO_VERSION}
CATEGORIES=	databases

COMMENT=	POCO C++ ODBC RDBMS Accessor libraries

.include "../../devel/poco/Makefile.common"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_DATA_ODBC=ON
CMAKE_CONFIGURE_ARGS+=	-DENABLE_FOUNDATION=OFF

.include "../../databases/poco-data/buildlink3.mk"
.include "../../databases/unixodbc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
