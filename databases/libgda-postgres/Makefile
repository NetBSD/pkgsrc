# $NetBSD: Makefile,v 1.20 2012/03/03 00:14:24 wiz Exp $
#

LIBGDA_PROVIDER=	postgres
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../databases/libgda/Makefile.common"

PKGREVISION=		6
CONFIGURE_ARGS+=	--with-postgres=${PGSQL_PREFIX:Q}

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
