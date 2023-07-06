# $NetBSD: Makefile,v 1.13 2023/07/06 09:41:01 wiz Exp $

PKGREVISION= 1
.include "../../net/freeradius/Makefile.module"

PKGNAME=	${DISTNAME:S/-server/-perl/}
COMMENT=	Free RADIUS rlm_perl module

CONFIGURE_ARGS+=	--with-rlm_perl
CONFIGURE_ARGS+=	--without-rlm_ldap
CONFIGURE_ARGS+=	--without-rlm_yubikey

do-install:
	${INSTALL_LIB} ${WRKSRC}/build/lib/.libs/rlm_perl.${SOEXT} \
		${DESTDIR}${PREFIX}/lib

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
