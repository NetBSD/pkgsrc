# $NetBSD: Makefile,v 1.21 2023/04/19 08:11:11 adam Exp $

PKGREVISION= 15
.include "../../net/proftpd/Makefile.module"

PROFTPD_MOD=	sqlite
PKGNAME=	${DISTNAME:S/proftpd/proftpd-${PROFTPD_MOD}/}
COMMENT=	SQLite module for ProFTPD

CONFIGURE_ARGS+=	--with-shared=mod_sql_sqlite

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
