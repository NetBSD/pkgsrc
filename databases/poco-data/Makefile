# $NetBSD: Makefile,v 1.14 2026/09/02 19:01:18 wiz Exp $

PKGNAME=	poco-data-${POCO_VERSION}
PKGREVISION=	1
CATEGORIES=	databases

COMMENT=	POCO C++ RDBMS Master Accessor libraries

.include "../../devel/poco/Makefile.common"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_DATA=ON
CMAKE_CONFIGURE_ARGS+=	-DENABLE_FOUNDATION=OFF

.include "../../devel/poco/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
