# $NetBSD: Makefile.php,v 1.10 2025/02/08 02:57:59 taca Exp $
# used by lang/php56/Makefile
# used by www/ap-php/Makefile
# used by www/php-fpm/Makefile

USE_LIBTOOL=		YES
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		YES
BUILD_DEFS+=		VARBASE
PLIST_VARS+=		dtrace

.include "../../lang/php56/Makefile.common"

DISTINFO_FILE=	${.CURDIR}/../../lang/php56/distinfo
PATCHDIR=	${.CURDIR}/../../lang/php56/patches

PLIST_SUBST+=	PHP_VER="${PHP_VER}"

PRINT_PLIST_AWK+=	/${PHP_EXTENSION_DIR:S/\//\\\//g}/ \
			{ sub(/${PHP_EXTENSION_DIR:S/\//\\\//g}/, \
				"$${PHP_EXTENSION_DIR}") }
PRINT_PLIST_AWK+=	/${PHP_VER}/ { sub(/${PHP_VER}/, "$${PHP_VER}") }

CONFIGURE_ARGS+=	--program-suffix=${PHP_VER}
CONFIGURE_ARGS+=	--with-config-file-path=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-config-file-scan-dir=${PKG_SYSCONFDIR}/php.d
CONFIGURE_ARGS+=	--with-pear=${PREFIX}/${PHP_LIBDIR}

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}

CONFIGURE_ARGS+=	--with-regex=system

CONFIGURE_ARGS+=	--without-mysql
CONFIGURE_ARGS+=	--without-iconv
CONFIGURE_ARGS+=	--without-pear
CONFIGURE_ARGS+=	--without-sqlite3

CONFIGURE_ARGS+=	--disable-posix
CONFIGURE_ARGS+=	--disable-opcache
CONFIGURE_ARGS+=	--disable-pdo
CONFIGURE_ARGS+=	--disable-json

CONFIGURE_ARGS+=	--enable-mysqlnd
CONFIGURE_ARGS+=	--enable-xml
CONFIGURE_ARGS+=	--with-libxml-dir=${PREFIX}

CONFIGURE_ENV+=		PHP_VER=${PHP_VER}
CONFIGURE_ENV+=		PHP_VAR_SUBST=PHP_VER
CONFIGURE_ENV+=		EXTENSION_DIR="${PREFIX}/${PHP_EXTENSION_DIR}"

SUBST_CLASSES+=		path
SUBST_MESSAGE.path=	Fixing common paths.
SUBST_STAGE.path=	pre-configure
SUBST_FILES.path+=	php.ini-development php.ini-production
SUBST_FILES.path+=	sapi/cgi/Makefile.frag
SUBST_FILES.path+=	sapi/fpm/php-fpm.conf.in
SUBST_FILES.path+=	sapi/fpm/fpm/fpm_conf.c
SUBST_FILES.path+=	scripts/php-config.in scripts/phpize.in
SUBST_VARS.path+=	PREFIX CGIDIR PHP_VER PHP_API_VERS
SUBST_VARS.path+=	PHP_EGDIR PHP_INCDIR PHP_LIBDIR

.include "../../textproc/libxml2/buildlink3.mk"

.include "options.mk"

DL_AUTO_VARS=		yes
.include "../../mk/dlopen.buildlink3.mk"
