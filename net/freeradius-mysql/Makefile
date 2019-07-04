# $NetBSD: Makefile,v 1.3 2019/07/04 07:44:52 adam Exp $

.include "../../net/freeradius/Makefile.module"

PKGNAME=	${DISTNAME:S/-server/-mysql/}
COMMENT=	Free RADIUS MySQL support

CONFIGURE_ARGS+=	--with-rlm_sql_mysql
CONFIGURE_ARGS+=	--without-rlm_ldap
CONFIGURE_ARGS+=	--without-rlm_yubikey

do-install:
	${INSTALL_LIB} ${WRKSRC}/build/lib/.libs/rlm_sql_mysql.${SOEXT} \
		${DESTDIR}${PREFIX}/lib

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
