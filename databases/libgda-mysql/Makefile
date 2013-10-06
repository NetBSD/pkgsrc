# $NetBSD: Makefile,v 1.14 2013/10/06 19:55:38 joerg Exp $
#

LIBGDA_PROVIDER=	mysql

.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client}

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
