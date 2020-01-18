# $NetBSD: Makefile,v 1.18 2020/01/18 21:48:56 jperkin Exp $

LIBGDA_PROVIDER=	mysql

PKGREVISION= 1
.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client}

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
