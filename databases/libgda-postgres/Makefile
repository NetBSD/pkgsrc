# $NetBSD: Makefile,v 1.36 2022/04/18 19:10:36 adam Exp $

LIBGDA_PROVIDER=	postgres

PKGREVISION= 7
.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-postgres=${PGSQL_PREFIX:Q}

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
