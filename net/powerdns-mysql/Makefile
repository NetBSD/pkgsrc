# $NetBSD: Makefile,v 1.11 2012/10/03 12:51:48 fhajny Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../net/powerdns/Makefile.backend"

PKGNAME=		${DISTNAME:S/pdns/powerdns-mysql/}
PKGREVISION=		3
COMMENT=		MySQL backend module for PowerDNS

CONFIGURE_ARGS+=	--with-dynmodules="gmysql"
CONFIGURE_ARGS+=	--with-mysql-lib=${BUILDLINK_PREFIX.mysql-client}/${BUILDLINK_LIBDIRS.mysql-client}
CONFIGURE_ARGS+=	--with-mysql-includes=${BUILDLINK_PREFIX.mysql-client}/${BUILDLINK_INCDIRS.mysql-client}

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
