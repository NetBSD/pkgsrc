# $NetBSD: Makefile,v 1.1 2015/09/25 10:01:36 wiedi Exp $

.include "../../net/proftpd/Makefile.module"

PROFTPD_MOD=	memcache
PKGNAME=	${DISTNAME:S/proftpd/proftpd-${PROFTPD_MOD}/}
COMMENT=	Memcache module for ProFTPD

CONFIGURE_ARGS+=	--with-shared=mod_memcache:mod_tls_memcache

.include "../../devel/libmemcached/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
