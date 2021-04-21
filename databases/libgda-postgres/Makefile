# $NetBSD: Makefile,v 1.34 2021/04/21 11:41:12 adam Exp $

LIBGDA_PROVIDER=	postgres

PKGREVISION= 5
.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-postgres=${PGSQL_PREFIX:Q}

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
