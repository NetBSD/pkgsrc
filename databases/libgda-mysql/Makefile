# $NetBSD: Makefile,v 1.1.1.1 2007/01/26 11:02:12 dillo Exp $
#

LIBGDA_PROVIDER=	mysql

.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-=mysql

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
