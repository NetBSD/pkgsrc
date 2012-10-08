# $NetBSD: Makefile,v 1.11 2012/10/08 12:19:26 asau Exp $

PERDITION_COMMENT=	PostgreSQL user database module
PERDITION_PKGNAME=	postgresql
PERDITION_SKIP_DISABLE=	pg
PKGREVISION=		2

USE_TOOLS+=	bash:run
REPLACE_BASH+=	perdition/db/postgresql/perditiondb_postgresql_makedb

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mail/perdition/Makefile.common"
