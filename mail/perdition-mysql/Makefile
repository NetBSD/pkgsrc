# $NetBSD: Makefile,v 1.5 2010/06/02 12:50:04 adam Exp $

PERDITION_COMMENT=	MySQL user database module
PERDITION_PKGNAME=	mysql

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	bash:run
REPLACE_BASH+=	perdition/db/mysql/perditiondb_mysql_makedb

.include "../../mk/mysql.buildlink3.mk"
.include "../../mail/perdition/Makefile.common"
