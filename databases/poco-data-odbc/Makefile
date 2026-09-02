# $NetBSD: Makefile,v 1.15 2026/09/02 19:01:18 wiz Exp $

PKGNAME=	poco-data-odbc-${POCO_VERSION}
PKGREVISION=	1
CATEGORIES=	databases

COMMENT=	POCO C++ ODBC RDBMS Accessor libraries

.include "../../devel/poco/Makefile.common"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_DATA_ODBC=ON
CMAKE_CONFIGURE_ARGS+=	-DENABLE_FOUNDATION=OFF

.include "../../databases/poco-data/buildlink3.mk"
.include "../../databases/unixodbc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
