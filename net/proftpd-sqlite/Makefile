# $NetBSD: Makefile,v 1.5.4.1 2017/04/05 21:54:26 spz Exp $

.include "../../net/proftpd/Makefile.module"

PROFTPD_MOD=	sqlite
PKGNAME=	${DISTNAME:S/proftpd/proftpd-${PROFTPD_MOD}/}
COMMENT=	SQLite module for ProFTPD

CONFIGURE_ARGS+=	--with-shared=mod_sql_sqlite

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
