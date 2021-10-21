# $NetBSD: Makefile,v 1.4 2021/10/21 07:46:36 wiz Exp $

PKGREVISION= 1
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
