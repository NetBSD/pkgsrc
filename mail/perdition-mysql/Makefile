# $NetBSD: Makefile,v 1.10 2013/03/02 20:33:28 wiz Exp $

PERDITION_COMMENT=	MySQL user database module
PERDITION_PKGNAME=	mysql
PKGREVISION=		4

USE_TOOLS+=	bash:run
REPLACE_BASH+=	perdition/db/mysql/perditiondb_mysql_makedb

.include "../../mk/mysql.buildlink3.mk"
.include "../../mail/perdition/Makefile.common"
