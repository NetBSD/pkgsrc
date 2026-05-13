# $NetBSD: Makefile,v 1.32 2026/05/13 09:30:43 adam Exp $

.include "../../net/freeradius/Makefile.module"

PKGNAME=	${DISTNAME:S/-server/-sqlite3/}
COMMENT=	Free RADIUS SQLite support

CONFIGURE_ARGS+=	--with-rlm_sql_iodbc
CONFIGURE_ARGS+=	--without-rlm_ldap
CONFIGURE_ARGS+=	--without-rlm_yubikey

do-install:
	${INSTALL_LIB} ${WRKSRC}/build/lib/.libs/rlm_sql_sqlite.${SHLIB_EXT} \
		${DESTDIR}${PREFIX}/lib

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
