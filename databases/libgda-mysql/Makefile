# $NetBSD: Makefile,v 1.29 2023/11/08 13:18:25 wiz Exp $

LIBGDA_PROVIDER=	mysql

PKGREVISION= 12
.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client}

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
