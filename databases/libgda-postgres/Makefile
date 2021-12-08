# $NetBSD: Makefile,v 1.35 2021/12/08 16:03:38 adam Exp $

LIBGDA_PROVIDER=	postgres

PKGREVISION= 6
.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-postgres=${PGSQL_PREFIX:Q}

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
