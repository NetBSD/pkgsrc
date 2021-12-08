# $NetBSD: Makefile,v 1.24 2021/12/08 16:03:38 adam Exp $

LIBGDA_PROVIDER=	mysql

PKGREVISION= 7
.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client}

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
