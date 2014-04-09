# $NetBSD: Makefile,v 1.2 2014/04/09 07:27:15 obache Exp $

.include "../../net/powerdns/Makefile.backend"

PKGNAME=		${DISTNAME:S/pdns/powerdns-sqlite3/}
PKGREVISION=		1
COMMENT=		SQLite version 3 backend module for PowerDNS

CONFIGURE_ARGS+=	--with-dynmodules="gsqlite3"
CONFIGURE_ARGS+=	--with-sqlite3-lib=${BUILDLINK_PREFIX.sqlite3}/lib
CONFIGURE_ARGS+=	--with-sqlite3-includes=${BUILDLINK_PREFIX.sqlite3}/include

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
