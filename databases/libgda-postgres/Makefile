# $NetBSD: Makefile,v 1.41 2024/05/29 16:31:41 adam Exp $

LIBGDA_PROVIDER=	postgres

PKGREVISION= 12
.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-postgres=${PGSQL_PREFIX:Q}

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
