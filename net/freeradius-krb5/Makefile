# $NetBSD: Makefile,v 1.2 2018/09/25 12:16:36 jperkin Exp $

.include "../../net/freeradius/Makefile.module"

PKGNAME=		${DISTNAME:S/-server/-krb5/}
COMMENT=		Free RADIUS rlm_krb5 module
CATEGORIES=		net

CONFIGURE_ARGS+=    --with-rlm_krb5
CONFIGURE_ARGS+=    --without-rlm_ldap

do-install:
	${INSTALL_LIB} ${WRKSRC}/build/lib/.libs/rlm_krb5.so ${DESTDIR}${PREFIX}/lib

.include "../../mk/krb5.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
