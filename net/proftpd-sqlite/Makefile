# $NetBSD: Makefile,v 1.29 2025/04/17 21:52:02 wiz Exp $

PKGREVISION= 5
.include "../../net/proftpd/Makefile.module"

PROFTPD_MOD=	sqlite
PKGNAME=	${DISTNAME:S/proftpd/proftpd-${PROFTPD_MOD}/}
COMMENT=	SQLite module for ProFTPD

CONFIGURE_ARGS+=	--with-shared=mod_sql_sqlite

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
