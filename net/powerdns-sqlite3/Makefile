# $NetBSD: Makefile,v 1.1.1.1 2013/09/06 11:01:57 fhajny Exp $

.include "../../net/powerdns/Makefile.backend"

PKGNAME=		${DISTNAME:S/pdns/powerdns-sqlite3/}
COMMENT=		SQLite version 3 backend module for PowerDNS

CONFIGURE_ARGS+=	--with-dynmodules="gsqlite3"
CONFIGURE_ARGS+=	--with-sqlite3-lib=${BUILDLINK_PREFIX.sqlite3}/lib
CONFIGURE_ARGS+=	--with-sqlite3-includes=${BUILDLINK_PREFIX.sqlite3}/include

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
