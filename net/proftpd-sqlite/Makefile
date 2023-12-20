# $NetBSD: Makefile,v 1.24 2023/12/20 17:05:01 wiz Exp $

.include "../../net/proftpd/Makefile.module"

PROFTPD_MOD=	sqlite
PKGNAME=	${DISTNAME:S/proftpd/proftpd-${PROFTPD_MOD}/}
COMMENT=	SQLite module for ProFTPD

CONFIGURE_ARGS+=	--with-shared=mod_sql_sqlite

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
