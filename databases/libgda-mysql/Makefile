# $NetBSD: Makefile,v 1.30 2024/05/29 16:31:41 adam Exp $

LIBGDA_PROVIDER=	mysql

PKGREVISION= 13
.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client}

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
