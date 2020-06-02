# $NetBSD: Makefile,v 1.32 2020/06/02 08:23:25 adam Exp $

LIBGDA_PROVIDER=	postgres

PKGREVISION= 3
.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-postgres=${PGSQL_PREFIX:Q}

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
