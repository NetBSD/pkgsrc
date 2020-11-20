# $NetBSD: Makefile.php,v 1.3 2020/11/20 15:13:31 otis Exp $
# used by lang/php74/Makefile
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

.include "../../lang/php74/Makefile.common"

DISTINFO_FILE=	${.CURDIR}/../../lang/php74/distinfo
PATCHDIR=	${.CURDIR}/../../lang/php74/patches

CONFIGURE_ARGS+=	--with-config-file-path=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-config-file-scan-dir=${PKG_SYSCONFDIR}/php.d
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
CONFIGURE_ARGS+=	--disable-json

CONFIGURE_ARGS+=	--enable-cgi
CONFIGURE_ARGS+=	--enable-mysqlnd
CONFIGURE_ARGS+=	--enable-xml
#CONFIGURE_ARGS+=	--with-libxml-dir=${PREFIX}

CONFIGURE_ENV+=		EXTENSION_DIR="${PREFIX}/${PHP_EXTENSION_DIR}"

.include "../../textproc/libxml2/buildlink3.mk"

#CONFIGURE_ARGS+=	--with-pcre-regex=${BUILDLINK_PREFIX.pcre2}

PKG_OPTIONS_VAR=	PKG_OPTIONS.${PHP_PKG_PREFIX}
PKG_SUPPORTED_OPTIONS+=	inet6 ssl maintainer-zts readline argon2 php-embed
PKG_SUPPORTED_OPTIONS+=	disable-filter-url
PKG_SUGGESTED_OPTIONS+=	inet6 ssl readline

.if ${OPSYS} == "SunOS" || ${OPSYS} == "Darwin" || ${OPSYS} == "FreeBSD"
PKG_SUPPORTED_OPTIONS+=	dtrace
.endif

.include "../../mk/bsd.options.mk"

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

.if !empty(PKG_OPTIONS:Mreadline)
.include "../../devel/readline/buildlink3.mk"
CONFIGURE_ARGS+=	--with-readline=${BUILDLINK_PREFIX.readline}
.else
CONFIGURE_ARGS+=	--without-readline
.endif

.if !empty(PKG_OPTIONS:Mdtrace)
PLIST.dtrace=		yes
CONFIGURE_ARGS+=	--enable-dtrace

# See https://bugs.php.net/bug.php?id=61268
INSTALL_MAKE_FLAGS+=	-r
.endif

.if !empty(PKG_OPTIONS:Margon2)
CONFIGURE_ARGS+=	--with-password-argon2=${BUILDLINK_PREFIX.argon2}
.include "../../security/argon2/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mdisable-filter-url)
CFLAGS+=		-DDISABLE_FILTER_URL
.endif

PLIST_VARS+=    embed

.if !empty(PKG_OPTIONS:Mphp-embed)
CONFIGURE_ARGS+=	--enable-embed
INSTALLATION_DIRS+=	include/php/sapi/embed
PLIST.embed=		yes

.PHONY: post-install-embed
post-install: post-install-embed
post-install-embed:
	${INSTALL_DATA} ${WRKSRC}/sapi/embed/php_embed.h ${DESTDIR}${PREFIX}/include/php/sapi/embed/
	${INSTALL_LIB} ${WRKSRC}/libs/libphp7.so ${DESTDIR}${PREFIX}/lib/
.endif

DL_AUTO_VARS=		yes
.include "../../mk/dlopen.buildlink3.mk"
