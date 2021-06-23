# $NetBSD: Makefile,v 1.4 2021/06/23 20:33:14 nia Exp $

.include "../../net/freeradius/Makefile.module"

PKGNAME=	${DISTNAME:S/-server/-mysql/}
PKGREVISION=	1
COMMENT=	Free RADIUS MySQL support

CONFIGURE_ARGS+=	--with-rlm_sql_mysql
CONFIGURE_ARGS+=	--without-rlm_ldap
CONFIGURE_ARGS+=	--without-rlm_yubikey

do-install:
	${INSTALL_LIB} ${WRKSRC}/build/lib/.libs/rlm_sql_mysql.${SOEXT} \
		${DESTDIR}${PREFIX}/lib

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
