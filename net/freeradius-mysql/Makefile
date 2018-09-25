# $NetBSD: Makefile,v 1.2 2018/09/25 12:16:36 jperkin Exp $

.include "../../net/freeradius/Makefile.module"

PKGNAME=		${DISTNAME:S/-server/-mysql/}
COMMENT=		Free RADIUS MySQL support
CATEGORIES=		net

CONFIGURE_ARGS+=    --with-rlm_sql_mysql
CONFIGURE_ARGS+=    --without-rlm_ldap

do-install:
	${INSTALL_LIB} ${WRKSRC}/build/lib/.libs/rlm_sql_mysql.so ${DESTDIR}${PREFIX}/lib

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
