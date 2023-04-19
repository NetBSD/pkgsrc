# $NetBSD: Makefile,v 1.27 2023/04/19 08:09:24 adam Exp $

LIBGDA_PROVIDER=	mysql

PKGREVISION= 10
.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client}

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
