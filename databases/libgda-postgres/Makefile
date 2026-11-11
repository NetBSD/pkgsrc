# $NetBSD: Makefile,v 1.51 2026/11/11 11:52:11 wiz Exp $

LIBGDA_PROVIDER=	postgres

PKGREVISION= 22
.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-postgres=${PGSQL_PREFIX:Q}

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
