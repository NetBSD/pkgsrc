# $NetBSD: Makefile,v 1.3 2025/05/06 12:07:34 wiz Exp $

.include "../../net/freeradius/Makefile.module"

PKGNAME=	${DISTNAME:S/-server/-pgsql/}
COMMENT=	Free RADIUS PostgreSQL support
CATEGORIES=	net

CONFIGURE_ARGS+=	--with-rlm_sql_postgresql
CONFIGURE_ARGS+=	--without-rlm_yubikey

do-install:
	${INSTALL_LIB} ${WRKSRC}/build/lib/.libs/rlm_sql_postgresql.${SHLIB_EXT} \
		${DESTDIR}${PREFIX}/lib

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
