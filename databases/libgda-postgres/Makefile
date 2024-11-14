# $NetBSD: Makefile,v 1.44 2024/11/14 22:19:00 wiz Exp $

LIBGDA_PROVIDER=	postgres

PKGREVISION= 15
.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-postgres=${PGSQL_PREFIX:Q}

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
