# $NetBSD: Makefile,v 1.9 2012/10/08 12:19:26 asau Exp $

PERDITION_COMMENT=	MySQL user database module
PERDITION_PKGNAME=	mysql
PKGREVISION=		3

USE_TOOLS+=	bash:run
REPLACE_BASH+=	perdition/db/mysql/perditiondb_mysql_makedb

.include "../../mk/mysql.buildlink3.mk"
.include "../../mail/perdition/Makefile.common"
