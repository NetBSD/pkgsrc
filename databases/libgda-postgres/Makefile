# $NetBSD: Makefile,v 1.37 2022/11/23 16:19:35 adam Exp $

LIBGDA_PROVIDER=	postgres

PKGREVISION= 8
.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-postgres=${PGSQL_PREFIX:Q}

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
