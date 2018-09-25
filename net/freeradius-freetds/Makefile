# $NetBSD: Makefile,v 1.6 2018/09/25 12:20:05 jperkin Exp $

.include "../../net/freeradius/Makefile.module"

PKGNAME=		${DISTNAME:S/-server/-freetds/}
COMMENT=		Free RADIUS FreeTDS support
CATEGORIES=		net

CONFIGURE_ARGS+=    --with-rlm_sql_freetds
CONFIGURE_ARGS+=    --without-rlm_ldap

do-install:
	${INSTALL_LIB} ${WRKSRC}/build/lib/.libs/rlm_sql_freetds.so ${DESTDIR}${PREFIX}/lib

.include "../../databases/freetds/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
