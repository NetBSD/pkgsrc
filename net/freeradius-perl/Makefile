# $NetBSD: Makefile,v 1.4 2018/09/25 12:20:05 jperkin Exp $

.include "../../net/freeradius/Makefile.module"

PKGNAME=		${DISTNAME:S/-server/-perl/}
COMMENT=		Free RADIUS rlm_perl module
CATEGORIES=		net

CONFIGURE_ARGS+=    --with-rlm_perl
CONFIGURE_ARGS+=    --without-rlm_ldap

do-install:
	${INSTALL_LIB} ${WRKSRC}/build/lib/.libs/rlm_perl.so ${DESTDIR}${PREFIX}/lib

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
