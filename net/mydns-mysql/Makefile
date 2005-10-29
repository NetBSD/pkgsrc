# $NetBSD: Makefile,v 1.1.1.1 2005/10/29 16:59:17 minskim Exp $

PKGNAME=	${DISTNAME:S/-/-mysql-/}
COMMENT=	MySQL-based DNS server

CONFLICTS=	mydns-pgsql-[0-9]*

DISTINFO_FILE=	${.CURDIR}/../../net/mydns-pgsql/distinfo
PATCHDIR=	${.CURDIR}/../../net/mydns-pgsql/patches
FILESDIR=	${.CURDIR}/../../net/mydns-pgsql/files

CONFIGURE_ARGS+=	--without-pgsql
CONFIGURE_ARGS+=	--with-mysql-lib=${BUILDLINK_PREFIX.mysql-client}/lib/mysql
CONFIGURE_ARGS+=	--with-mysql-include=${BUILDLINK_PREFIX.mysql-client}/include/mysql

.include	"../../mk/mysql.buildlink3.mk"
.include	"../../net/mydns-pgsql/Makefile.common"
