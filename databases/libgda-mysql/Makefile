# $NetBSD: Makefile,v 1.12 2012/10/02 21:25:21 asau Exp $
#

LIBGDA_PROVIDER=	mysql

.include "../../databases/libgda/Makefile.common"

PKGREVISION=		8
CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client}

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
