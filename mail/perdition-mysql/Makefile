# $NetBSD: Makefile,v 1.11 2021/06/23 20:33:13 nia Exp $

PERDITION_COMMENT=	MySQL user database module
PERDITION_PKGNAME=	mysql
PKGREVISION=		5

USE_TOOLS+=	bash:run
REPLACE_BASH+=	perdition/db/mysql/perditiondb_mysql_makedb

.include "../../mk/mysql.buildlink3.mk"
.include "../../mail/perdition/Makefile.common"
