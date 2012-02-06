# $NetBSD: Makefile,v 1.6 2012/02/06 12:39:44 wiz Exp $
#

LIBGDA_PROVIDER=	mysql
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../databases/libgda/Makefile.common"

PKGREVISION=		4
CONFIGURE_ARGS+=	--with-=mysql

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
