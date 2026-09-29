# $NetBSD: Makefile,v 1.20 2026/09/29 06:04:15 wiz Exp $

PKGNAME=	poco-data-mysql-${POCO_VERSION}
PKGREVISION=	3
CATEGORIES=	databases

COMMENT=	POCO C++ MySQL RDBMS Accessor libraries

.include "../../devel/poco/Makefile.common"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_DATA_MYSQL=ON
CMAKE_CONFIGURE_ARGS+=	-DENABLE_FOUNDATION=OFF

.include "../../databases/poco-data/buildlink3.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
