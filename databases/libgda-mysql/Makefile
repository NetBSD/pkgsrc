# $NetBSD: Makefile,v 1.33 2024/11/14 22:19:00 wiz Exp $

LIBGDA_PROVIDER=	mysql

PKGREVISION= 16
.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client}

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
