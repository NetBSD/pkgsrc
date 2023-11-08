# $NetBSD: Makefile,v 1.40 2023/11/08 13:18:25 wiz Exp $

LIBGDA_PROVIDER=	postgres

PKGREVISION= 11
.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-postgres=${PGSQL_PREFIX:Q}

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
