# $NetBSD: Makefile,v 1.17 2019/05/17 08:20:34 wiz Exp $

LIBGDA_PROVIDER=	mysql

.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client}

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
