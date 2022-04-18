# $NetBSD: Makefile,v 1.25 2022/04/18 19:10:36 adam Exp $

LIBGDA_PROVIDER=	mysql

PKGREVISION= 8
.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client}

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
