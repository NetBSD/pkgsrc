# $NetBSD: Makefile,v 1.3 2019/07/04 07:44:52 adam Exp $

.include "../../net/freeradius/Makefile.module"

PKGNAME=	${DISTNAME:S/-server/-krb5/}
COMMENT=	Free RADIUS rlm_krb5 module

CONFIGURE_ARGS+=	--with-rlm_krb5
CONFIGURE_ARGS+=	--without-rlm_ldap
CONFIGURE_ARGS+=	--without-rlm_yubikey

do-install:
	${INSTALL_LIB} ${WRKSRC}/build/lib/.libs/rlm_krb5.${SOEXT} \
		${DESTDIR}${PREFIX}/lib

.include "../../mk/krb5.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
