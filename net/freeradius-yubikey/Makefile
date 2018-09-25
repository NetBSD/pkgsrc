# $NetBSD: Makefile,v 1.2 2018/09/25 12:16:37 jperkin Exp $

.include "../../net/freeradius/Makefile.module"

PKGNAME=		${DISTNAME:S/-server/-yubikey/}
COMMENT=		Free RADIUS rlm_yubikey module
CATEGORIES=		net

CONFIGURE_ARGS+=    --with-rlm_yubikey
CONFIGURE_ARGS+=    --without-rlm_ldap

do-install:
	${INSTALL_LIB} ${WRKSRC}/build/lib/.libs/rlm_yubikey.so ${DESTDIR}${PREFIX}/lib

.include "../../security/libyubikey/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
