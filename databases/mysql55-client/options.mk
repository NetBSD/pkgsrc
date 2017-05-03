# $NetBSD: options.mk,v 1.13 2017/05/03 12:37:01 mef Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mysql5

# ndb-cluster does not configure with cmake
PKG_SUPPORTED_OPTIONS+=	dtrace embedded-server ndb-cluster sphinx
PKG_SUGGESTED_OPTIONS+=	embedded-server

.include "../../mk/bsd.options.mk"

.	include "../../security/openssl/buildlink3.mk"

# Enable DTrace support
.if !empty(PKG_OPTIONS:Mdtrace)
CMAKE_ARGS+=		-DENABLE_DTRACE=ON
.else
CMAKE_ARGS+=		-DENABLE_DTRACE=OFF
.endif

# Enable Sphinx SE support
# http://sphinxsearch.com/docs/current.html#sphinxse-overview
PLIST_VARS+=	sphinx
.if !empty(PKG_OPTIONS:Msphinx) || make(distinfo) || make(makesum) || make(mdi)
SPHINX_VER=	2.2.11
DISTFILES=	${DEFAULT_DISTFILES} sphinx-${SPHINX_VER}-release${EXTRACT_SUFX}
SITES.sphinx-2.2.11-release.tar.gz=	http://sphinxsearch.com/files/
.if !empty(PKGPATH:Mdatabases/mysql55-server)
MESSAGE_SRC=	${PKGDIR}/MESSAGE ${PKGDIR}/MESSAGE.sphinx
.endif
PLIST.sphinx=	yes

post-extract:
	${CP} -R ${WRKDIR}/sphinx-${SPHINX_VER}-release/mysqlse ${WRKSRC}/storage/sphinx
.endif
