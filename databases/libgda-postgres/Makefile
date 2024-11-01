# $NetBSD: Makefile,v 1.43 2024/11/01 12:51:46 wiz Exp $

LIBGDA_PROVIDER=	postgres

PKGREVISION= 14
.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-postgres=${PGSQL_PREFIX:Q}

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
