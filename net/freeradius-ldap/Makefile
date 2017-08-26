# $NetBSD: Makefile,v 1.1 2017/08/26 10:07:28 fhajny Exp $

.include "../../net/freeradius/Makefile.module"

PKGNAME=		${DISTNAME:S/-server/-ldap/}
COMMENT=		Free RADIUS rlm_ldap module
CATEGORIES=		net

CONFIGURE_ARGS+=    --with-rlm_ldap

do-install:
	${INSTALL_LIB} ${WRKSRC}/build/lib/.libs/rlm_ldap.so ${DESTDIR}${PREFIX}/lib

.include "../../databases/openldap-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
