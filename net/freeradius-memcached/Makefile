# $NetBSD: Makefile,v 1.2 2018/09/25 12:16:36 jperkin Exp $

.include "../../net/freeradius/Makefile.module"

PKGNAME=		${DISTNAME:S/-server/-memcached/}
COMMENT=		Free RADIUS support for memcached
CATEGORIES=		net

CONFIGURE_ARGS+=    --with-rlm_cache_memcached
CONFIGURE_ARGS+=    --without-rlm_ldap

do-install:
	${INSTALL_LIB} ${WRKSRC}/build/lib/.libs/rlm_cache_memcached.so ${DESTDIR}${PREFIX}/lib

.include "../../devel/libmemcached/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
