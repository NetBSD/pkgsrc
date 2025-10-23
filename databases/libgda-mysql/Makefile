# $NetBSD: Makefile,v 1.35 2025/10/23 20:36:10 wiz Exp $

LIBGDA_PROVIDER=	mysql

PKGREVISION= 18
.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client}

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
