# $NetBSD: Makefile,v 1.9 2011/04/22 13:45:19 obache Exp $

PERDITION_COMMENT=	PostgreSQL user database module
PERDITION_PKGNAME=	postgresql
PERDITION_SKIP_DISABLE=	pg
PKGREVISION=		1

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	bash:run
REPLACE_BASH+=	perdition/db/postgresql/perditiondb_postgresql_makedb

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mail/perdition/Makefile.common"
