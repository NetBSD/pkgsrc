# $NetBSD: Makefile,v 1.19 2025/06/30 11:02:57 jperkin Exp $

.include "../../net/powerdns/backend.mk"

PKGNAME=		${DISTNAME:S/pdns/powerdns-mysql/}
COMMENT=		MySQL backend module for PowerDNS

CONFIGURE_ARGS+=	--with-dynmodules="gmysql"
CONFIGURE_ARGS+=	--with-mysql-lib=${BUILDLINK_PREFIX.mysql-client}/${BUILDLINK_LIBDIRS.mysql-client}
CONFIGURE_ARGS+=	--with-mysql-includes=${BUILDLINK_PREFIX.mysql-client}/${BUILDLINK_INCDIRS.mysql-client}

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
