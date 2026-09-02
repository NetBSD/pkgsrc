# $NetBSD: Makefile,v 1.48 2026/09/02 19:01:16 wiz Exp $

LIBGDA_PROVIDER=	postgres

PKGREVISION= 19
.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-postgres=${PGSQL_PREFIX:Q}

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
