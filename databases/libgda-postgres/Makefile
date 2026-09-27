# $NetBSD: Makefile,v 1.49 2026/09/27 11:35:20 tnn Exp $

LIBGDA_PROVIDER=	postgres

PKGREVISION= 20
.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-postgres=${PGSQL_PREFIX:Q}

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
