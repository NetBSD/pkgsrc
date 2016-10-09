# $NetBSD: Makefile,v 1.13 2016/10/09 21:42:00 wiz Exp $

PERDITION_COMMENT=	PostgreSQL user database module
PERDITION_PKGNAME=	postgresql
PERDITION_SKIP_DISABLE=	pg
PKGREVISION=		4

USE_TOOLS+=	bash:run
REPLACE_BASH+=	perdition/db/postgresql/perditiondb_postgresql_makedb

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mail/perdition/Makefile.common"
