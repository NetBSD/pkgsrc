# $NetBSD: Makefile,v 1.3 2008/01/04 20:05:12 jmmv Exp $

.include "../../net/powerdns/Makefile.backend"

PKGNAME=		${DISTNAME:S/pdns/powerdns-mysql/}
PKGREVISION=		1
COMMENT=		MySQL backend module for PowerDNS

CONFIGURE_ARGS+=	--with-dynmodules="gmysql"
CONFIGURE_ARGS+=	--with-mysql-lib=${BUILDLINK_PREFIX.mysql-client}/lib/mysql
CONFIGURE_ARGS+=	--with-mysql-includes=${BUILDLINK_PREFIX.mysql-client}/include/mysql

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
