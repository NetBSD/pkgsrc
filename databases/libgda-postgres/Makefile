# $NetBSD: Makefile,v 1.13 2007/01/21 19:14:46 wiz Exp $
#

LIBGDA_PROVIDER=	postgres

.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-postgres=${PGSQL_PREFIX:Q}

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
