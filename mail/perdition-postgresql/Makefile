# $NetBSD: Makefile,v 1.6 2008/06/12 02:14:35 joerg Exp $
#

PKGREVISION=		4

PERDITION_COMMENT=	PostgreSQL user database module
PERDITION_PKGNAME=	postgresql
PERDITION_SKIP_DISABLE=	pg

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	bash:run
REPLACE_BASH+=	perdition/db/postgresql/perditiondb_postgresql_makedb

.include "../../mk/pgsql.buildlink3.mk"
.include "../perdition/Makefile.common"
