# $NetBSD: Makefile,v 1.21 2012/06/14 07:45:08 sbd Exp $
#

LIBGDA_PROVIDER=	postgres
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../databases/libgda/Makefile.common"

PKGREVISION=		7
CONFIGURE_ARGS+=	--with-postgres=${PGSQL_PREFIX:Q}

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
