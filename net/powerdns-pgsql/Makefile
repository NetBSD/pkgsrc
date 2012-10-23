# $NetBSD: Makefile,v 1.13 2012/10/23 17:18:59 asau Exp $

.include "../../net/powerdns/Makefile.backend"

PKGNAME=		${DISTNAME:S/pdns/powerdns-pgsql/}
PKGREVISION=		3
COMMENT=		PostgreSQL backend module for PowerDNS

CONFIGURE_ARGS+=	--with-dynmodules="gpgsql"
CONFIGURE_ARGS+=	--with-pgsql-lib=${BUILDLINK_PREFIX.${PGSQL_TYPE}}/lib
CONFIGURE_ARGS+=	--with-pgsql-includes=${BUILDLINK_PREFIX.${PGSQL_TYPE}}/include

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
