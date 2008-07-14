# $NetBSD: Makefile,v 1.15 2008/07/14 12:56:00 joerg Exp $
#

LIBGDA_PROVIDER=	postgres
PKGREVISION=	1
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-postgres=${PGSQL_PREFIX:Q}

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
