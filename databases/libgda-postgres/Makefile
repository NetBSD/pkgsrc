# $NetBSD: Makefile,v 1.33 2020/11/05 09:07:41 ryoon Exp $

LIBGDA_PROVIDER=	postgres

PKGREVISION= 4
.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-postgres=${PGSQL_PREFIX:Q}

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
