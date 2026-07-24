# $NetBSD: Makefile,v 1.13 2026/07/24 12:15:54 adam Exp $

PKGNAME=	poco-data-${POCO_VERSION}
CATEGORIES=	databases

COMMENT=	POCO C++ RDBMS Master Accessor libraries

.include "../../devel/poco/Makefile.common"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_DATA=ON
CMAKE_CONFIGURE_ARGS+=	-DENABLE_FOUNDATION=OFF

.include "../../devel/poco/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
