# $NetBSD: Makefile,v 1.4 2025/05/06 12:07:35 wiz Exp $

.include "../../net/freeradius/Makefile.module"

PKGNAME=	${DISTNAME:S/-server/-yubikey/}
COMMENT=	Free RADIUS rlm_yubikey module

CONFIGURE_ARGS+=	--with-rlm_yubikey
CONFIGURE_ARGS+=	--without-rlm_ldap

do-install:
	${INSTALL_LIB} ${WRKSRC}/build/lib/.libs/rlm_yubikey.${SHLIB_EXT} \
		${DESTDIR}${PREFIX}/lib

.include "../../security/libyubikey/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
