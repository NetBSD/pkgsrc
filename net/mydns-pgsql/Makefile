# $NetBSD: Makefile,v 1.23 2014/06/10 14:21:37 joerg Exp $

PKGNAME=		${DISTNAME:S/-/-pgsql-/}
PKGREVISION=		15
COMMENT=		PostgreSQL-based DNS server

CONFLICTS=		mydns-mysql-[0-9]*

CONFIGURE_ARGS+=	--without-mysql
CONFIGURE_ARGS+=	--with-pgsql-lib=${BUILDLINK_PREFIX.${PGSQL_TYPE}}/lib
CONFIGURE_ARGS+=	--with-pgsql-include=${BUILDLINK_PREFIX.${PGSQL_TYPE}}/include

INFO_FILES=		yes

.include "../../mk/pgsql.buildlink3.mk"
.include "Makefile.common"
