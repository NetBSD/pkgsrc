# $NetBSD: Makefile,v 1.4 2005/02/25 17:22:43 drochner Exp $
#

LIBGDA_PROVIDER=	postgres

.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-postgres=${PGSQL_PREFIX}

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
