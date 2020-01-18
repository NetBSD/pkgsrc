# $NetBSD: Makefile,v 1.30 2020/01/18 21:48:56 jperkin Exp $

LIBGDA_PROVIDER=	postgres

PKGREVISION= 1
.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-postgres=${PGSQL_PREFIX:Q}

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
