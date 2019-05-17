# $NetBSD: Makefile,v 1.29 2019/05/17 08:20:34 wiz Exp $

LIBGDA_PROVIDER=	postgres

.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-postgres=${PGSQL_PREFIX:Q}

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
