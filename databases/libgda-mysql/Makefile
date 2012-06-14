# $NetBSD: Makefile,v 1.9 2012/06/14 07:45:08 sbd Exp $
#

LIBGDA_PROVIDER=	mysql
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../databases/libgda/Makefile.common"

PKGREVISION=		6
CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client}

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
