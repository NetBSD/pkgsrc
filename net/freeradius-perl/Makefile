# $NetBSD: Makefile,v 1.1 2017/08/26 10:07:28 fhajny Exp $

.include "../../net/freeradius/Makefile.module"

PKGNAME=		${DISTNAME:S/-server/-perl/}
COMMENT=		Free RADIUS rlm_perl module
CATEGORIES=		net

CONFIGURE_ARGS+=    --with-rlm_perl

do-install:
	${INSTALL_LIB} ${WRKSRC}/build/lib/.libs/rlm_perl.so ${DESTDIR}${PREFIX}/lib

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
