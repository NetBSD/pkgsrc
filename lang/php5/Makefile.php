# $NetBSD: Makefile.php,v 1.1 2004/11/04 18:38:55 jdolecek Exp $
#

.include "../../lang/php5/Makefile.common"

BUILD_DEFS=		USE_INET6

USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES

CONFIGURE_ENV+=		EXTENSION_DIR="${PREFIX}/${PHP_EXTENSION_DIR}"

PHP_EXTENSION_DIR=	lib/php/20040412
PLIST_SUBST+=		PHP_EXTENSION_DIR=${PHP_EXTENSION_DIR}

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--with-config-file-path=${PREFIX}/etc/
CONFIGURE_ARGS+=	--with-regex=system

CONFIGURE_ARGS+=	--without-mysql
CONFIGURE_ARGS+=	--without-sqlite
CONFIGURE_ARGS+=	--without-iconv

CONFIGURE_ARGS+=	--enable-discard-path
CONFIGURE_ARGS+=	--enable-force-cgi-redirect
CONFIGURE_ARGS+=	--enable-memory-limit
CONFIGURE_ARGS+=	--enable-track-vars

CONFIGURE_ARGS+=	--disable-posix
CONFIGURE_ARGS+=	--disable-dom

.if defined(USE_INET6) && ${USE_INET6} == "NO"
CONFIGURE_ARGS+=	--disable-ipv6
.else
CONFIGURE_ARGS+=	--enable-ipv6
.endif

CONFIGURE_ARGS+=	--enable-xml
CONFIGURE_ARGS+=	--with-libxml-dir=${PREFIX}
.include "../../textproc/libxml2/buildlink3.mk"

# Global and legacy options
.if defined(USE_SSL) && !empty(USE_SSL:M[Yy][Ee][Ss])
PKG_DEFAULT_OPTIONS+=	ssl
.endif

PKG_OPTIONS_VAR=		PKG_OPTIONS.${PKGNAME:C/-[^-]*$//}
PKG_SUPPORTED_OPTIONS+=	ssl
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mssl)
.  include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-openssl
.endif
