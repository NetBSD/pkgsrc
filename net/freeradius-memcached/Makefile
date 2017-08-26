# $NetBSD: Makefile,v 1.1 2017/08/26 10:07:28 fhajny Exp $

.include "../../net/freeradius/Makefile.module"

PKGNAME=		${DISTNAME:S/-server/-memcached/}
COMMENT=		Free RADIUS support for memcached
CATEGORIES=		net

CONFIGURE_ARGS+=    --with-rlm_cache_memcached

do-install:
	${INSTALL_LIB} ${WRKSRC}/build/lib/.libs/rlm_cache_memcached.so ${DESTDIR}${PREFIX}/lib

.include "../../devel/libmemcached/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
