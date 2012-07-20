# $NetBSD: Makefile.php,v 1.19 2012/07/20 12:28:17 taca Exp $
# used by lang/php53/Makefile
# used by www/ap-php/Makefile

.include "../../lang/php53/Makefile.common"

DISTINFO_FILE=	${.CURDIR}/../../lang/php53/distinfo
PATCHDIR=	${.CURDIR}/../../lang/php53/patches

USE_LIBTOOL=		YES
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		YES
BUILD_DEFS+=		VARBASE
PLIST_VARS+=		suhosin

CONFIGURE_ENV+=		EXTENSION_DIR="${PREFIX}/${PHP_EXTENSION_DIR}"

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--with-config-file-path=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-config-file-scan-dir=${PKG_SYSCONFDIR}/php.d
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}

CONFIGURE_ARGS+=	--with-regex=system

CONFIGURE_ARGS+=	--without-mysql
CONFIGURE_ARGS+=	--without-sqlite
#CONFIGURE_ARGS+=	--without-sqlite3
CONFIGURE_ARGS+=	--without-iconv
CONFIGURE_ARGS+=	--without-pear
#CONFIGURE_ARGS+=	--without-intl

CONFIGURE_ARGS+=	--disable-posix
CONFIGURE_ARGS+=	--disable-dom
CONFIGURE_ARGS+=	--disable-pdo
CONFIGURE_ARGS+=	--disable-json

CONFIGURE_ARGS+=	--enable-cgi
CONFIGURE_ARGS+=	--enable-xml
CONFIGURE_ARGS+=	--with-libxml-dir=${PREFIX}
.include "../../textproc/libxml2/buildlink3.mk"

# Note: This expression is the same as ${PKGBASE}, but the latter is
# not defined yet, so we cannot use it here.
PKG_OPTIONS_VAR=	PKG_OPTIONS.${PKGNAME:C/-[0-9].*//}
PKG_SUPPORTED_OPTIONS+=	inet6 ssl maintainer-zts suhosin
PKG_SUGGESTED_OPTIONS+=	inet6 ssl

#SUBST_CLASSES+=		ini
#SUBST_STAGE.ini=	post-patch
#SUBST_FILES.ini=	php.ini-development
#SUBST_FILES.ini+=	php.ini-production
#SUBST_SED.ini=		-e "s|\\;include_path = \".:/php/includes\"|include_path = \".:${PREFIX}/lib/php\"|g"
#SUBST_MESSAGE.ini=	Fixing default ini files.

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msuhosin)
SUHOSIN_PHPVER=		5.3.9
.  if ${SUHOSIN_PHPVER} != ${PHP_BASE_VERS} && ${PHP_BASE_VERS} != 5.3.15
PKG_FAIL_REASON+=	"The suhosin patch is currently not available for"
PKG_FAIL_REASON+=	"this version of PHP.  You may have to wait until"
PKG_FAIL_REASON+=	"an updated patch is released or temporarily"
PKG_FAIL_REASON+=	"build this package without the suhosin option."
.  else
PATCH_SITES=		http://download.suhosin.org/
PATCHFILES+=		suhosin-patch-${SUHOSIN_PHPVER}-0.9.10.patch.gz
PATCH_DIST_STRIP=	-p1
PLIST.suhosin=		yes
MESSAGE_SRC=		${.CURDIR}/../../lang/php53/MESSAGE
MESSAGE_SRC+=		${.CURDIR}/../../lang/php53/MESSAGE.suhosin
.  endif
.endif

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if !empty(PKG_OPTIONS:Mssl)
.  include "../../security/openssl/buildlink3.mk"
.  if ${OPSYS} == "SunOS"
CONFIGURE_ARGS+=	--with-openssl=yes
LIBS.SunOS+=		-lcrypto
.  else
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}
.  endif
.else
CONFIGURE_ARGS+=	--without-openssl
.endif

.if !empty(PKG_OPTIONS:Mmaintainer-zts)
CONFIGURE_ARGS+=	--enable-maintainer-zts
.endif

DL_AUTO_VARS=		yes
.include "../../mk/dlopen.buildlink3.mk"
