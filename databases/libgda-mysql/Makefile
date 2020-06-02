# $NetBSD: Makefile,v 1.20 2020/06/02 08:23:25 adam Exp $

LIBGDA_PROVIDER=	mysql

PKGREVISION= 3
.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client}

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
