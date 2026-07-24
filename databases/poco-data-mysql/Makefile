# $NetBSD: Makefile,v 1.17 2026/07/24 12:15:54 adam Exp $

PKGNAME=	poco-data-mysql-${POCO_VERSION}
CATEGORIES=	databases

COMMENT=	POCO C++ MySQL RDBMS Accessor libraries

.include "../../devel/poco/Makefile.common"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_DATA_MYSQL=ON
CMAKE_CONFIGURE_ARGS+=	-DENABLE_FOUNDATION=OFF

.include "../../databases/poco-data/buildlink3.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
