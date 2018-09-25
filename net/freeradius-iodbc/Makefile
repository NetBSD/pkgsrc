# $NetBSD: Makefile,v 1.2 2018/09/25 12:16:36 jperkin Exp $

.include "../../net/freeradius/Makefile.module"

PKGNAME=		${DISTNAME:S/-server/-iodbc/}
COMMENT=		Free RADIUS iODBC support
CATEGORIES=		net

CONFIGURE_ARGS+=    --with-rlm_sql_iodbc
CONFIGURE_ARGS+=    --without-rlm_ldap

do-install:
	${INSTALL_LIB} ${WRKSRC}/build/lib/.libs/rlm_sql_iodbc.so ${DESTDIR}${PREFIX}/lib

.include "../../databases/iodbc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
