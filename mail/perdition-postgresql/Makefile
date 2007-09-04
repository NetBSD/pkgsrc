# $NetBSD: Makefile,v 1.4 2007/09/04 21:27:02 joerg Exp $
#

PKGREVISION=		3

PERDITION_COMMENT=	PostgreSQL user database module
PERDITION_PKGNAME=	postgresql
PERDITION_SKIP_DISABLE=	pg

USE_TOOLS+=	bash:run
REPLACE_BASH+=	perdition/db/postgresql/perditiondb_postgresql_makedb

.include "../../mk/pgsql.buildlink3.mk"
.include "../perdition/Makefile.common"
