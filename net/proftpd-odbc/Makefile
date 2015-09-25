# $NetBSD: Makefile,v 1.1 2015/09/25 10:01:37 wiedi Exp $

.include "../../net/proftpd/Makefile.module"

PROFTPD_MOD=	odbc
PKGNAME=	${DISTNAME:S/proftpd/proftpd-${PROFTPD_MOD}/}
COMMENT=	ODBC module for ProFTPD

CONFIGURE_ARGS+=	--with-shared=mod_sql_odbc

.include "../../databases/unixodbc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
