# $NetBSD: Makefile,v 1.15 2014/02/12 23:17:39 tron Exp $

LIBGDA_PROVIDER=	mysql
PKGREVISION=		1

.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client}

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
