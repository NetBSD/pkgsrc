# $NetBSD: Makefile,v 1.1 2014/05/22 12:50:48 fhajny Exp $

PKGNAME=		${DISTNAME:S/sqlrelay/sqlrelay-pgsql/}
COMMENT=		PostgreSQL support for SQL Relay

.include "../../databases/sqlrelay/Makefile.common"

LICENSE=		postgresql-license

CONFIGURE_ARGS+=	--with-postgresql-prefix=${PGSQL_PREFIX}

BUILD_DIRS=		src/connections/postgresql

.include "../../databases/sqlrelay/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
