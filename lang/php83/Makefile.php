# $NetBSD: Makefile.php,v 1.3 2025/02/08 02:59:57 taca Exp $
# used by lang/php83/Makefile
# used by www/ap-php/Makefile
# used by www/php-fpm/Makefile

# segfaults when buidling with many compilers
# https://bugs.php.net/bug.php?id=74527
# https://gcc.gnu.org/bugzilla/show_bug.cgi?id=86236
.if ${MACHINE_ARCH} == "i386"
CONFIGURE_ARGS+=	--disable-gcc-global-regs
.endif

# the binary actually needs full dep on PCRE
BUILDLINK_DEPMETHOD.pcre2=	full

USE_LIBTOOL=		YES
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		YES
BUILD_DEFS+=		VARBASE
PLIST_VARS+=		dtrace

.include "../../lang/php83/Makefile.common"

DISTINFO_FILE=	${.CURDIR}/../../lang/php83/distinfo
PATCHDIR=	${.CURDIR}/../../lang/php83/patches

PLIST_SUBST+=	PHP_VER="${PHP_VER}"

PRINT_PLIST_AWK+=	/${PHP_EXTENSION_DIR:S/\//\\\//g}/ \
			{ sub(/${PHP_EXTENSION_DIR:S/\//\\\//g}/, \
				"$${PHP_EXTENSION_DIR}") }
PRINT_PLIST_AWK+=	/${PHP_VER}/ { sub(/${PHP_VER}/, "$${PHP_VER}") }

CONFIGURE_ARGS+=	--program-suffix=${PHP_VER}
CONFIGURE_ARGS+=	--with-config-file-path=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-config-file-scan-dir=${PKG_SYSCONFDIR}/php.d
CONFIGURE_ARGS+=	--with-pear=${PREFIX}/{PHP_LIBDIR}

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}

CONFIGURE_ARGS+=	--without-mysqli
CONFIGURE_ARGS+=	--without-iconv
CONFIGURE_ARGS+=	--without-pear
CONFIGURE_ARGS+=	--without-sqlite3
CONFIGURE_ARGS+=	--with-external-pcre

CONFIGURE_ARGS+=	--disable-intl
CONFIGURE_ARGS+=	--disable-posix
CONFIGURE_ARGS+=	--disable-opcache
CONFIGURE_ARGS+=	--disable-pdo

CONFIGURE_ARGS+=	--enable-cgi
CONFIGURE_ARGS+=	--enable-mysqlnd
CONFIGURE_ARGS+=	--enable-xml
#CONFIGURE_ARGS+=	--with-libxml-dir=${PREFIX}

CONFIGURE_ENV+=		PHP_VER=${PHP_VER}
CONFIGURE_ENV+=		PHP_VAR_SUBST=PHP_VER
CONFIGURE_ENV+=		EXTENSION_DIR="${PREFIX}/${PHP_EXTENSION_DIR}"

SUBST_CLASSES+=		path
SUBST_MESSAGE.path=	Fixing common paths.
SUBST_STAGE.path=	pre-configure
SUBST_FILES.path+=	build/php.m4
SUBST_FILES.path+=	php.ini-development php.ini-production
SUBST_FILES.path+=	sapi/cgi/Makefile.frag
SUBST_FILES.path+=	sapi/fpm/php-fpm.conf.in sapi/fpm/www.conf.in
SUBST_FILES.path+=	sapi/fpm/fpm/fpm_conf.c
SUBST_FILES.path+=	scripts/php-config.in scripts/phpize.in
SUBST_VARS.path=	PREFIX CGIDIR PHP_VER PHP_API_VERS
SUBST_VARS.path+=	PHP_EGDIR PHP_INCDIR PHP_LIBDIR
SUBST_VARS.path+=	TOOLS_PATH.pkg-config PHP_PKGCONFIG_PATH

.include "../../textproc/libxml2/buildlink3.mk"

#CONFIGURE_ARGS+=	--with-pcre-regex=${BUILDLINK_PREFIX.pcre2}

.include "options.mk"

DL_AUTO_VARS=		yes
.include "../../mk/dlopen.buildlink3.mk"
