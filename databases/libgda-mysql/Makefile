# $NetBSD: Makefile,v 1.23 2021/06/23 20:33:07 nia Exp $

LIBGDA_PROVIDER=	mysql

PKGREVISION= 6
.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client}

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
