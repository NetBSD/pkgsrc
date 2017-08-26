# $NetBSD: Makefile,v 1.1 2017/08/26 10:07:28 fhajny Exp $

.include "../../net/freeradius/Makefile.module"

PKGNAME=		${DISTNAME:S/-server/-krb5/}
COMMENT=		Free RADIUS rlm_krb5 module
CATEGORIES=		net

CONFIGURE_ARGS+=    --with-rlm_krb5

do-install:
	${INSTALL_LIB} ${WRKSRC}/build/lib/.libs/rlm_krb5.so ${DESTDIR}${PREFIX}/lib

.include "../../mk/krb5.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
