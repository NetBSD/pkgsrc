# $NetBSD: Makefile,v 1.27 2016/03/05 11:28:11 jperkin Exp $

LIBGDA_PROVIDER=	postgres
PKGREVISION=		2

.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-postgres=${PGSQL_PREFIX:Q}

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
