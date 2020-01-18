# $NetBSD: Makefile,v 1.26 2020/01/18 21:50:19 jperkin Exp $

PKGNAME=		${DISTNAME:S/-/-pgsql-/}
PKGREVISION=		18
COMMENT=		PostgreSQL-based DNS server

CONFLICTS=		mydns-mysql-[0-9]*

CONFIGURE_ARGS+=	--without-mysql
CONFIGURE_ARGS+=	--with-pgsql-lib=${BUILDLINK_PREFIX.${PGSQL_TYPE}}/lib
CONFIGURE_ARGS+=	--with-pgsql-include=${BUILDLINK_PREFIX.${PGSQL_TYPE}}/include

INFO_FILES=		yes

.include "../../mk/pgsql.buildlink3.mk"
.include "Makefile.common"
