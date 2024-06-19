# $NetBSD: Makefile,v 1.27 2024/06/19 08:46:33 adam Exp $

.include "../../net/freeradius/Makefile.module"

PKGNAME=	${DISTNAME:S/-server/-freetds/}
COMMENT=	Free RADIUS FreeTDS support

CONFIGURE_ARGS+=	--with-rlm_sql_freetds
CONFIGURE_ARGS+=	--without-rlm_ldap
CONFIGURE_ARGS+=	--without-rlm_yubikey

do-install:
	${INSTALL_LIB} ${WRKSRC}/build/lib/.libs/rlm_sql_freetds.${SOEXT} \
		${DESTDIR}${PREFIX}/lib

.include "../../databases/freetds/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
