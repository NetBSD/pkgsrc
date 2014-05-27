# $NetBSD: Makefile,v 1.2 2014/05/27 13:25:46 fhajny Exp $

PKGNAME=		${DISTNAME:S/sqlrelay/sqlrelay-odbc/}
COMMENT=		ODBC support for SQL Relay

.include "../../databases/sqlrelay/Makefile.common"

LICENSE=		gnu-lgpl-v2

CONFIGURE_ARGS+=	--with-odbc-prefix=${BUILDLINK_PREFIX.unixodbc}

BUILD_DIRS=		src/connections/odbc

.include "../../databases/sqlrelay/buildlink3.mk"
.include "../../databases/unixodbc/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
