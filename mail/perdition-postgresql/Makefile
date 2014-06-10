# $NetBSD: Makefile,v 1.12 2014/06/10 14:21:37 joerg Exp $

PERDITION_COMMENT=	PostgreSQL user database module
PERDITION_PKGNAME=	postgresql
PERDITION_SKIP_DISABLE=	pg
PKGREVISION=		3

USE_TOOLS+=	bash:run
REPLACE_BASH+=	perdition/db/postgresql/perditiondb_postgresql_makedb

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mail/perdition/Makefile.common"
