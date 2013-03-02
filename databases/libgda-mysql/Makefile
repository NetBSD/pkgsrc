# $NetBSD: Makefile,v 1.13 2013/03/02 20:33:23 wiz Exp $
#

LIBGDA_PROVIDER=	mysql

.include "../../databases/libgda/Makefile.common"

PKGREVISION=		9
CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client}

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
