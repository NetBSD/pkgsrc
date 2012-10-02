# $NetBSD: Makefile,v 1.24 2012/10/02 21:25:21 asau Exp $
#

LIBGDA_PROVIDER=	postgres

.include "../../databases/libgda/Makefile.common"

PKGREVISION=		9
CONFIGURE_ARGS+=	--with-postgres=${PGSQL_PREFIX:Q}

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
