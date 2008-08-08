# $NetBSD: Makefile.php,v 1.28 2008/08/08 20:01:34 adrianp Exp $
#

.include "../../lang/php5/Makefile.common"

DISTINFO_FILE=	${.CURDIR}/../../lang/php5/distinfo
PATCHDIR=	${.CURDIR}/../../lang/php5/patches

USE_LIBTOOL=		YES
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		YES
BUILD_DEFS+=		VARBASE

CONFIGURE_ENV+=		EXTENSION_DIR="${PREFIX}/${PHP_EXTENSION_DIR}"

PHP_EXTENSION_DIR=	lib/php/20040412
PLIST_SUBST+=		PHP_EXTENSION_DIR=${PHP_EXTENSION_DIR:Q}

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--with-config-file-path=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}

CONFIGURE_ARGS+=	--with-regex=system

CONFIGURE_ARGS+=	--without-mysql
CONFIGURE_ARGS+=	--without-sqlite
CONFIGURE_ARGS+=	--without-iconv
CONFIGURE_ARGS+=	--without-pear

CONFIGURE_ARGS+=	--disable-posix
CONFIGURE_ARGS+=	--disable-dom
CONFIGURE_ARGS+=	--disable-pdo
CONFIGURE_ARGS+=	--disable-json

CONFIGURE_ARGS+=	--enable-xml
CONFIGURE_ARGS+=	--with-libxml-dir=${PREFIX:Q}
.include "../../textproc/libxml2/buildlink3.mk"

# Note: This expression is the same as ${PKGBASE}, but the latter is
# not defined yet, so we cannot use it here.
PKG_OPTIONS_VAR=	PKG_OPTIONS.${PKGNAME:C/-[0-9].*//}
PKG_SUPPORTED_OPTIONS+=	inet6 ssl maintainer-zts
PKG_SUGGESTED_OPTIONS+=	ssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if !empty(PKG_OPTIONS:Mssl)
.  include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}
.else
CONFIGURE_ARGS+=	--without-openssl
.endif

.if !empty(PKG_OPTIONS:Mmaintainer-zts)
CONFIGURE_ARGS+=	--enable-maintainer-zts
.endif
