# $NetBSD: Makefile,v 1.22 2025/06/30 11:03:53 jperkin Exp $

.include "../../net/powerdns/backend.mk"

PKGNAME=		${DISTNAME:S/pdns/powerdns-pgsql/}
COMMENT=		PostgreSQL backend module for PowerDNS

CONFIGURE_ARGS+=	--with-dynmodules="gpgsql"
CONFIGURE_ARGS+=	--with-pgsql-lib=${BUILDLINK_PREFIX.${PGSQL_TYPE}}/lib
CONFIGURE_ARGS+=	--with-pgsql-includes=${BUILDLINK_PREFIX.${PGSQL_TYPE}}/include

BUILDLINK_TRANSFORM.OpenBSD+=	rm:-lcrypt

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
