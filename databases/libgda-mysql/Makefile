# $NetBSD: Makefile,v 1.19 2020/03/08 16:49:05 wiz Exp $

LIBGDA_PROVIDER=	mysql

PKGREVISION= 2
.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client}

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
