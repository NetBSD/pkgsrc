# $NetBSD: Makefile,v 1.7 2025/05/06 12:07:33 wiz Exp $

.include "../../net/freeradius/Makefile.module"

PKGNAME=	${DISTNAME:S/-server/-ldap/}
COMMENT=	Free RADIUS rlm_ldap module

CONFIGURE_ARGS+=	--with-rlm_ldap
CONFIGURE_ARGS+=	--without-rlm_yubikey

do-install:
	${INSTALL_LIB} ${WRKSRC}/build/lib/.libs/rlm_ldap.${SHLIB_EXT} \
		${DESTDIR}${PREFIX}/lib

.include "../../databases/openldap-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
