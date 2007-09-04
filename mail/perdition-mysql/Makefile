# $NetBSD: Makefile,v 1.3 2007/09/04 21:08:53 joerg Exp $
#

PKGREVISION=		2

PERDITION_COMMENT=	MySQL user database module
PERDITION_PKGNAME=	mysql

USE_TOOLS+=	bash:run
REPLACE_BASH+=	perdition/db/mysql/perditiondb_mysql_makedb

.include "../../mk/mysql.buildlink3.mk"
.include "../perdition/Makefile.common"
