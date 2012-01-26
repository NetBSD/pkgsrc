# $NetBSD: Makefile,v 1.4.30.1 2012/01/26 23:39:09 tron Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../net/powerdns/Makefile.backend"

PKGNAME=		${DISTNAME:S/pdns/powerdns-sqlite/}
PKGREVISION=		2
COMMENT=		SQLite backend module for PowerDNS

CONFIGURE_ARGS+=	--with-dynmodules="gsqlite"
CONFIGURE_ARGS+=	--with-sqlite-lib=${BUILDLINK_PREFIX.sqlite}/lib
CONFIGURE_ARGS+=	--with-sqlite-includes=${BUILDLINK_PREFIX.sqlite}/include

.include "../../databases/sqlite/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
