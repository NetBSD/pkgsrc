# $NetBSD: Makefile,v 1.3 2020/01/18 21:50:13 jperkin Exp $

PKGREVISION= 1
.include "../../net/freeradius/Makefile.module"

PKGNAME=	${DISTNAME:S/-server/-ldap/}
COMMENT=	Free RADIUS rlm_ldap module

CONFIGURE_ARGS+=	--with-rlm_ldap
CONFIGURE_ARGS+=	--without-rlm_yubikey

do-install:
	${INSTALL_LIB} ${WRKSRC}/build/lib/.libs/rlm_ldap.${SOEXT} \
		${DESTDIR}${PREFIX}/lib

.include "../../databases/openldap-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
