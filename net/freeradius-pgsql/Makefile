# $NetBSD: Makefile,v 1.2 2019/07/04 07:44:53 adam Exp $

.include "../../net/freeradius/Makefile.module"

PKGNAME=	${DISTNAME:S/-server/-pgsql/}
COMMENT=	Free RADIUS PostgreSQL support
CATEGORIES=	net

CONFIGURE_ARGS+=	--with-rlm_sql_postgresql
CONFIGURE_ARGS+=	--without-rlm_yubikey

do-install:
	${INSTALL_LIB} ${WRKSRC}/build/lib/.libs/rlm_sql_postgresql.${SOEXT} \
		${DESTDIR}${PREFIX}/lib

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
