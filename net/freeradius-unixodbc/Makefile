# $NetBSD: Makefile,v 1.1 2017/08/26 10:07:29 fhajny Exp $

.include "../../net/freeradius/Makefile.module"

PKGNAME=		${DISTNAME:S/-server/-unixodbc/}
COMMENT=		Free RADIUS UNIXODBC support
CATEGORIES=		net

CONFIGURE_ARGS+=    --with-rlm_sql_unixodbc

do-install:
	${INSTALL_LIB} ${WRKSRC}/build/lib/.libs/rlm_sql_unixodbc.so ${DESTDIR}${PREFIX}/lib

.include "../../databases/unixodbc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
