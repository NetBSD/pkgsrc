# $NetBSD: Makefile,v 1.45 2025/04/17 21:50:02 wiz Exp $

LIBGDA_PROVIDER=	postgres

PKGREVISION= 16
.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-postgres=${PGSQL_PREFIX:Q}

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
