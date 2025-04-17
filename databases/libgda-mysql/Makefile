# $NetBSD: Makefile,v 1.34 2025/04/17 21:50:02 wiz Exp $

LIBGDA_PROVIDER=	mysql

PKGREVISION= 17
.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client}

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
