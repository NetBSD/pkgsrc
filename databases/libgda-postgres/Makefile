# $NetBSD: Makefile,v 1.38 2023/04/19 08:09:24 adam Exp $

LIBGDA_PROVIDER=	postgres

PKGREVISION= 9
.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-postgres=${PGSQL_PREFIX:Q}

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
