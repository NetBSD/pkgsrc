# $NetBSD: Makefile,v 1.28 2023/10/24 22:08:27 wiz Exp $

LIBGDA_PROVIDER=	mysql

PKGREVISION= 11
.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client}

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
