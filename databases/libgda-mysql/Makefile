# $NetBSD: Makefile,v 1.22 2021/04/21 11:41:12 adam Exp $

LIBGDA_PROVIDER=	mysql

PKGREVISION= 5
.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client}

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
