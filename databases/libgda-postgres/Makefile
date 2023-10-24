# $NetBSD: Makefile,v 1.39 2023/10/24 22:08:27 wiz Exp $

LIBGDA_PROVIDER=	postgres

PKGREVISION= 10
.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-postgres=${PGSQL_PREFIX:Q}

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
