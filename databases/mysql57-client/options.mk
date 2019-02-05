# $NetBSD: options.mk,v 1.3 2019/02/05 20:19:55 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mysql5

# ndb-cluster does not configure with cmake
PKG_SUPPORTED_OPTIONS+=	dtrace embedded-server ndb-cluster
PKG_SUPPORTED_OPTIONS+=	memcached
PKG_SUGGESTED_OPTIONS+=	embedded-server

.include "../../mk/bsd.options.mk"

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
.else
CMAKE_ARGS+=		-DWITH_INNODB_MEMCACHED=OFF
.endif

# Enable Sphinx SE support
# http://sphinxsearch.com/docs/current.html#sphinxse-overview
#PLIST_VARS+=	sphinx
#.if !empty(PKG_OPTIONS:Msphinx) || make(distinfo) || make(makesum) || make(mdi)
#SPHINX_VER=	2.2.11
#DISTFILES=	${DEFAULT_DISTFILES} sphinx-${SPHINX_VER}-release${EXTRACT_SUFX}
#SITES.sphinx-2.2.11-release.tar.gz=	http://sphinxsearch.com/files/
#.  if !empty(PKGPATH:Mdatabases/mysql56-server)
#MESSAGE_SRC=	${PKGDIR}/MESSAGE ${PKGDIR}/MESSAGE.sphinx
#.  endif
#PLIST.sphinx=	yes

#post-extract:
#	${CP} -R ${WRKDIR}/sphinx-${SPHINX_VER}-release/mysqlse ${WRKSRC}/storage/sphinx
#.endif
