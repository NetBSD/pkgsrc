# $NetBSD: Makefile,v 1.3 2019/07/04 07:44:52 adam Exp $

.include "../../net/freeradius/Makefile.module"

PKGNAME=	${DISTNAME:S/-server/-memcached/}
COMMENT=	Free RADIUS support for memcached

CONFIGURE_ARGS+=	--with-rlm_cache_memcached
CONFIGURE_ARGS+=	--without-rlm_ldap
CONFIGURE_ARGS+=	--without-rlm_yubikey

do-install:
	${INSTALL_LIB} ${WRKSRC}/build/lib/.libs/rlm_cache_memcached.${SOEXT} \
		${DESTDIR}${PREFIX}/lib

.include "../../devel/libmemcached/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
