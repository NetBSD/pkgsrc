# $NetBSD: Makefile,v 1.11 2023/11/30 20:11:26 adam Exp $

DISTNAME=	qtbase-everywhere-src-${QTVERSION}
PKGNAME=	qt6-odbc-${QTVERSION}
COMMENT=	Qt6 odbc SQL driver
CATEGORIES=	databases

LICENSE=	gnu-lgpl-v3 OR gnu-gpl-v2 OR gnu-gpl-v3

CONFIGURE_ARGS+=	-sql-odbc
CONFIGURE_ARGS+=	-no-sql-db2
CONFIGURE_ARGS+=	-no-sql-ibase
CONFIGURE_ARGS+=	-no-sql-mysql
CONFIGURE_ARGS+=	-no-sql-oci
CONFIGURE_ARGS+=	-no-sql-psql
CONFIGURE_ARGS+=	-no-sql-sqlite

QTCONFDIR=		src/plugins/sqldrivers

.include "../../x11/qt6-qtbase/Makefile.common"

.include "../../databases/unixodbc/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
