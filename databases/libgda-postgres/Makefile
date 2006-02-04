# $NetBSD: Makefile,v 1.7 2006/02/04 17:02:46 wiz Exp $
#

LIBGDA_PROVIDER=	postgres

.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-postgres=${PGSQL_PREFIX:Q}

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
