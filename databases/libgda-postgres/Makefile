# $NetBSD: Makefile,v 1.46 2025/10/23 20:36:10 wiz Exp $

LIBGDA_PROVIDER=	postgres

PKGREVISION= 17
.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-postgres=${PGSQL_PREFIX:Q}

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
