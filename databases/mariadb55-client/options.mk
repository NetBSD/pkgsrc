# $NetBSD: options.mk,v 1.4 2017/08/08 11:23:38 fhajny Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mariadb55

# ndb-cluster does not configure with cmake
PKG_SUPPORTED_OPTIONS+=	dtrace embedded-server ndb-cluster sphinx ssl
PKG_SUGGESTED_OPTIONS+=	embedded-server ssl

.include "../../mk/bsd.options.mk"

# Enable OpenSSL support
.if !empty(PKG_OPTIONS:Mssl)
.	include "../../security/openssl/buildlink3.mk"
CMAKE_ARGS+=		-DWITH_SSL=system
.else
CMAKE_ARGS+=		-DWITH_SSL=no
.endif

## This doesn't seem to build at all currently
# Enable DTrace support
PLIST_VARS+=		dtrace
## This doesn't seem to build at all currently
## .if !empty(PKG_OPTIONS:Mdtrace)
## CMAKE_ARGS+=		-DENABLE_DTRACE=ON
## PLIST.dtrace=		yes
## .else
CMAKE_ARGS+=		-DENABLE_DTRACE=OFF
## .endif

# Enable Sphinx SE support
# http://sphinxsearch.com/docs/current.html#sphinxse-overview
PLIST_VARS+=	sphinx
.if !empty(PKG_OPTIONS:Msphinx) || make(distinfo) || make(makesum) || make(mdi)
SPHINX_VER=	2.2.11
DISTFILES=	${DEFAULT_DISTFILES} sphinx-${SPHINX_VER}-release${EXTRACT_SUFX}
SITES.sphinx-${SPHINX_VER}-release.tar.gz=	http://sphinxsearch.com/files/
.if !empty(PKGPATH:Mdatabases/mariadb55-server)
MESSAGE_SRC=	${PKGDIR}/MESSAGE ${PKGDIR}/MESSAGE.sphinx
.endif
PLIST.sphinx=	yes

post-extract:
	${CP} -R ${WRKDIR}/sphinx-${SPHINX_VER}-release/mysqlse ${WRKSRC}/storage/sphinx
.endif
