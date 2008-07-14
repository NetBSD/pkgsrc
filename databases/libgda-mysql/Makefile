# $NetBSD: Makefile,v 1.2 2008/07/14 12:56:00 joerg Exp $
#

LIBGDA_PROVIDER=	mysql
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-=mysql

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
