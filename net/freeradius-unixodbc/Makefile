# $NetBSD: Makefile,v 1.2 2018/09/25 12:16:37 jperkin Exp $

.include "../../net/freeradius/Makefile.module"

PKGNAME=		${DISTNAME:S/-server/-unixodbc/}
COMMENT=		Free RADIUS UNIXODBC support
CATEGORIES=		net

CONFIGURE_ARGS+=    --with-rlm_sql_unixodbc
CONFIGURE_ARGS+=    --without-rlm_ldap

do-install:
	${INSTALL_LIB} ${WRKSRC}/build/lib/.libs/rlm_sql_unixodbc.so ${DESTDIR}${PREFIX}/lib

.include "../../databases/unixodbc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
