# $NetBSD: Makefile,v 1.32 2024/11/01 12:51:46 wiz Exp $

LIBGDA_PROVIDER=	mysql

PKGREVISION= 15
.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client}

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
