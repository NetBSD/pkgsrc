# $NetBSD: Makefile,v 1.16 2016/03/05 11:28:11 jperkin Exp $

LIBGDA_PROVIDER=	mysql
PKGREVISION=		2

.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client}

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
