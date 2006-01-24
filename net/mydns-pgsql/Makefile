# $NetBSD: Makefile,v 1.4 2006/01/24 09:10:51 ghen Exp $

PKGNAME=		${DISTNAME:S/-/-pgsql-/}
PKGREVISION=		1
COMMENT=		PostgreSQL-based DNS server

CONFLICTS=		mydns-mysql-[0-9]*

CONFIGURE_ARGS+=	--without-mysql
CONFIGURE_ARGS+=	--with-pgsql-lib=${BUILDLINK_PREFIX.${PGSQL_TYPE}}/lib
CONFIGURE_ARGS+=	--with-pgsql-include=${BUILDLINK_PREFIX.${PGSQL_TYPE}}/include

.include "../../mk/pgsql.buildlink3.mk"
.include "Makefile.common"
