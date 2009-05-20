# $NetBSD: Makefile,v 1.3 2009/05/20 01:09:12 wiz Exp $
#

LIBGDA_PROVIDER=	mysql
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../databases/libgda/Makefile.common"

PKGREVISION=		1
CONFIGURE_ARGS+=	--with-=mysql

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
