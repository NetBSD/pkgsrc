# $NetBSD: Makefile,v 1.4 2025/05/06 12:07:34 wiz Exp $

.include "../../net/freeradius/Makefile.module"

PKGNAME=	${DISTNAME:S/-server/-memcached/}
COMMENT=	Free RADIUS support for memcached

CONFIGURE_ARGS+=	--with-rlm_cache_memcached
CONFIGURE_ARGS+=	--without-rlm_ldap
CONFIGURE_ARGS+=	--without-rlm_yubikey

do-install:
	${INSTALL_LIB} ${WRKSRC}/build/lib/.libs/rlm_cache_memcached.${SHLIB_EXT} \
		${DESTDIR}${PREFIX}/lib

.include "../../devel/libmemcached/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
