# $NetBSD: Makefile,v 1.3 2019/07/04 07:44:53 adam Exp $

.include "../../net/freeradius/Makefile.module"

PKGNAME=	${DISTNAME:S/-server/-unixodbc/}
COMMENT=	Free RADIUS UNIXODBC support

CONFIGURE_ARGS+=	--with-rlm_sql_unixodbc
CONFIGURE_ARGS+=	--without-rlm_ldap
CONFIGURE_ARGS+=	--without-rlm_yubikey

do-install:
	${INSTALL_LIB} ${WRKSRC}/build/lib/.libs/rlm_sql_unixodbc.${SOEXT} \
		${DESTDIR}${PREFIX}/lib

.include "../../databases/unixodbc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
