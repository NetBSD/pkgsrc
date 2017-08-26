# $NetBSD: Makefile,v 1.1 2017/08/26 10:07:28 fhajny Exp $

.include "../../net/freeradius/Makefile.module"

PKGNAME=		${DISTNAME:S/-server/-mysql/}
COMMENT=		Free RADIUS MySQL support
CATEGORIES=		net

CONFIGURE_ARGS+=    --with-rlm_sql_mysql

do-install:
	${INSTALL_LIB} ${WRKSRC}/build/lib/.libs/rlm_sql_mysql.so ${DESTDIR}${PREFIX}/lib

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
