# $NetBSD: Makefile,v 1.6 2010/09/30 10:49:12 obache Exp $

PERDITION_COMMENT=	MySQL user database module
PERDITION_PKGNAME=	mysql
PKGREVISION=		1

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	bash:run
REPLACE_BASH+=	perdition/db/mysql/perditiondb_mysql_makedb

.include "../../mk/mysql.buildlink3.mk"
.include "../../mail/perdition/Makefile.common"
