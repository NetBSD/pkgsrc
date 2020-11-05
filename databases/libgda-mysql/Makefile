# $NetBSD: Makefile,v 1.21 2020/11/05 09:07:41 ryoon Exp $

LIBGDA_PROVIDER=	mysql

PKGREVISION= 4
.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client}

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
