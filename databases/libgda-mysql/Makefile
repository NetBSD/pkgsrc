# $NetBSD: Makefile,v 1.7 2012/03/03 00:14:24 wiz Exp $
#

LIBGDA_PROVIDER=	mysql
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../databases/libgda/Makefile.common"

PKGREVISION=		5
CONFIGURE_ARGS+=	--with-=mysql

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
