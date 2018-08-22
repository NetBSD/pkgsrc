# $NetBSD: Makefile,v 1.2 2018/08/22 09:45:52 wiz Exp $

PKGREVISION= 1
.include "../../net/freeradius/Makefile.module"

PKGNAME=		${DISTNAME:S/-server/-perl/}
COMMENT=		Free RADIUS rlm_perl module
CATEGORIES=		net

CONFIGURE_ARGS+=    --with-rlm_perl

do-install:
	${INSTALL_LIB} ${WRKSRC}/build/lib/.libs/rlm_perl.so ${DESTDIR}${PREFIX}/lib

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
