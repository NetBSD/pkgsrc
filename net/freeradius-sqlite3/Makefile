# $NetBSD: Makefile,v 1.9 2018/12/09 18:52:39 adam Exp $

PKGREVISION= 1
.include "../../net/freeradius/Makefile.module"

PKGNAME=		${DISTNAME:S/-server/-sqlite3/}
COMMENT=		Free RADIUS SQLite support
CATEGORIES=		net

CONFIGURE_ARGS+=    --with-rlm_sql_iodbc
CONFIGURE_ARGS+=    --without-rlm_ldap

do-install:
	${INSTALL_LIB} ${WRKSRC}/build/lib/.libs/rlm_sql_sqlite.so ${DESTDIR}${PREFIX}/lib

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
