# $NetBSD: Makefile,v 1.5 2008/03/13 17:38:48 joerg Exp $
#

PKGREVISION=		4

PERDITION_COMMENT=	PostgreSQL user database module
PERDITION_PKGNAME=	postgresql
PERDITION_SKIP_DISABLE=	pg

USE_TOOLS+=	bash:run
REPLACE_BASH+=	perdition/db/postgresql/perditiondb_postgresql_makedb

.include "../../mk/pgsql.buildlink3.mk"
.include "../perdition/Makefile.common"
