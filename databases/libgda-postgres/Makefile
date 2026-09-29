# $NetBSD: Makefile,v 1.50 2026/09/29 06:04:12 wiz Exp $

LIBGDA_PROVIDER=	postgres

PKGREVISION= 21
.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-postgres=${PGSQL_PREFIX:Q}

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
