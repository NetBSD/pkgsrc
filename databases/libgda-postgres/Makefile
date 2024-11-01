# $NetBSD: Makefile,v 1.42 2024/11/01 00:50:59 wiz Exp $

LIBGDA_PROVIDER=	postgres

PKGREVISION= 13
.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-postgres=${PGSQL_PREFIX:Q}

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
