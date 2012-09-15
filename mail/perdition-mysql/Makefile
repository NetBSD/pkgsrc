# $NetBSD: Makefile,v 1.8 2012/09/15 15:03:24 obache Exp $

PERDITION_COMMENT=	MySQL user database module
PERDITION_PKGNAME=	mysql
PKGREVISION=		3

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	bash:run
REPLACE_BASH+=	perdition/db/mysql/perditiondb_mysql_makedb

.include "../../mk/mysql.buildlink3.mk"
.include "../../mail/perdition/Makefile.common"
