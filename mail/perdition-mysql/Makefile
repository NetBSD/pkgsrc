# $NetBSD: Makefile,v 1.4 2008/06/12 02:14:35 joerg Exp $
#

PKGREVISION=		2

PERDITION_COMMENT=	MySQL user database module
PERDITION_PKGNAME=	mysql

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	bash:run
REPLACE_BASH+=	perdition/db/mysql/perditiondb_mysql_makedb

.include "../../mk/mysql.buildlink3.mk"
.include "../perdition/Makefile.common"
