# $NetBSD: options.mk,v 1.14 2019/02/05 20:18:43 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mysql5

# ndb-cluster does not configure with cmake
PKG_SUPPORTED_OPTIONS+=	dtrace embedded-server ndb-cluster sphinx ssl
PKG_SUPPORTED_OPTIONS+=	memcached
PKG_SUGGESTED_OPTIONS+=	embedded-server ssl

.include "../../mk/bsd.options.mk"

# Enable OpenSSL support
.if !empty(PKG_OPTIONS:Mssl)
.  include "../../security/openssl/buildlink3.mk"
CMAKE_ARGS+=		-DWITH_SSL=system
.else
CMAKE_ARGS+=		-DWITH_SSL=no
.endif

# Enable DTrace support
.if !empty(PKG_OPTIONS:Mdtrace)
CMAKE_ARGS+=		-DENABLE_DTRACE=ON
.else
CMAKE_ARGS+=		-DENABLE_DTRACE=OFF
.endif

# Enable InnoDB Memcached support
PLIST_VARS+=		memcached
.if !empty(PKG_OPTIONS:Mmemcached)
PLIST.memcached=	yes
CMAKE_ARGS+=		-DWITH_INNODB_MEMCACHED=ON
CMAKE_ARGS+=		-DWITH_BUNDLED_MEMCACHED=ON
.include "../../devel/libevent/buildlink3.mk"
.else
CMAKE_ARGS+=		-DWITH_INNODB_MEMCACHED=OFF
.endif

# Enable Sphinx SE support
# http://sphinxsearch.com/docs/current.html#sphinxse-overview
PLIST_VARS+=	sphinx
.if !empty(PKG_OPTIONS:Msphinx) || make(distinfo) || make(makesum) || make(mdi)
SPHINX_VER=	2.2.11
DISTFILES=	${DEFAULT_DISTFILES} sphinx-${SPHINX_VER}-release${EXTRACT_SUFX}
SITES.sphinx-2.2.11-release.tar.gz=	http://sphinxsearch.com/files/
.  if ${PKGPATH} == "databases/mysql56-server"
MESSAGE_SRC=	${PKGDIR}/MESSAGE ${PKGDIR}/MESSAGE.sphinx
.  endif
PLIST.sphinx=	yes

post-extract:
	${CP} -R ${WRKDIR}/sphinx-${SPHINX_VER}-release/mysqlse ${WRKSRC}/storage/sphinx
.endif
