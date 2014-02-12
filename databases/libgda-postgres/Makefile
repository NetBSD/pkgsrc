# $NetBSD: Makefile,v 1.26 2014/02/12 23:17:39 tron Exp $

LIBGDA_PROVIDER=	postgres
PKGREVISION=		1

.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-postgres=${PGSQL_PREFIX:Q}

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
