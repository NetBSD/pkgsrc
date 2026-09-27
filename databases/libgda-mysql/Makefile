# $NetBSD: Makefile,v 1.38 2026/09/27 11:35:20 tnn Exp $

LIBGDA_PROVIDER=	mysql

PKGREVISION= 21
.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client}

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
