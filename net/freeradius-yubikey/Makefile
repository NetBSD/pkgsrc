# $NetBSD: Makefile,v 1.1 2017/08/26 10:07:29 fhajny Exp $

.include "../../net/freeradius/Makefile.module"

PKGNAME=		${DISTNAME:S/-server/-yubikey/}
COMMENT=		Free RADIUS rlm_yubikey module
CATEGORIES=		net

CONFIGURE_ARGS+=    --with-rlm_yubikey

do-install:
	${INSTALL_LIB} ${WRKSRC}/build/lib/.libs/rlm_yubikey.so ${DESTDIR}${PREFIX}/lib

.include "../../security/libyubikey/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
