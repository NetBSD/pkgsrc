# $NetBSD: Makefile,v 1.18 2011/04/22 13:45:17 obache Exp $
#

LIBGDA_PROVIDER=	postgres
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../databases/libgda/Makefile.common"

PKGREVISION=		4
CONFIGURE_ARGS+=	--with-postgres=${PGSQL_PREFIX:Q}

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
