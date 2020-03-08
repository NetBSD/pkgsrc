# $NetBSD: Makefile,v 1.31 2020/03/08 16:49:05 wiz Exp $

LIBGDA_PROVIDER=	postgres

PKGREVISION= 2
.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-postgres=${PGSQL_PREFIX:Q}

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
