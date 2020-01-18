# $NetBSD: Makefile,v 1.10 2020/01/18 21:50:13 jperkin Exp $

PKGREVISION= 1
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
