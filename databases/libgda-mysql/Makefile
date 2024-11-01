# $NetBSD: Makefile,v 1.31 2024/11/01 00:50:59 wiz Exp $

LIBGDA_PROVIDER=	mysql

PKGREVISION= 14
.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client}

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
