# $NetBSD: Makefile,v 1.26 2022/11/23 16:19:35 adam Exp $

LIBGDA_PROVIDER=	mysql

PKGREVISION= 9
.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client}

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
