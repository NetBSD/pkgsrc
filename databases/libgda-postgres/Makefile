# $NetBSD: Makefile,v 1.16 2009/05/20 01:09:12 wiz Exp $
#

LIBGDA_PROVIDER=	postgres
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../databases/libgda/Makefile.common"

PKGREVISION=		2
CONFIGURE_ARGS+=	--with-postgres=${PGSQL_PREFIX:Q}

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
