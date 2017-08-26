# $NetBSD: Makefile,v 1.1 2017/08/26 10:07:28 fhajny Exp $

.include "../../net/freeradius/Makefile.module"

PKGNAME=		${DISTNAME:S/-server/-pgsql/}
COMMENT=		Free RADIUS PostgreSQL support
CATEGORIES=		net

CONFIGURE_ARGS+=    --with-rlm_sql_postgresql

do-install:
	${INSTALL_LIB} ${WRKSRC}/build/lib/.libs/rlm_sql_postgresql.so ${DESTDIR}${PREFIX}/lib

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
