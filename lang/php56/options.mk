# $NetBSD: options.mk,v 1.1 2020/08/01 09:52:51 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.${PHP_PKG_PREFIX}
PKG_SUPPORTED_OPTIONS+=	inet6 ssl maintainer-zts readline disable-filter-url php-embed
PKG_SUGGESTED_OPTIONS+=	inet6 ssl

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
PATCH_SITES+=		http://zettasystem.com/
PATCHFILES+=		PHP-5.6.31-OpenSSL-1.1.0-compatibility-20170801.patch
PATCH_DIST_STRIP=	-p1
.else
CONFIGURE_ARGS+=	--without-openssl
.endif

.if !empty(PKG_OPTIONS:Mmaintainer-zts)
CONFIGURE_ARGS+=	--enable-maintainer-zts
.endif

.if !empty(PKG_OPTIONS:Mreadline)
USE_GNU_READLINE=	yes
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

.if !empty(PKG_OPTIONS:Mdisable-filter-url)
CFLAGS+=		-DDISABLE_FILTER_URL
.endif

PLIST_VARS+=	embed

.if !empty(PKG_OPTIONS:Mphp-embed)
CONFIGURE_ARGS+=	--enable-embed
INSTALLATION_DIRS+=	include/php/sapi/embed
PLIST.embed=		yes

.PHONY: post-install-embed
post-install: post-install-embed
post-install-embed:
	${INSTALL_DATA} ${WRKSRC}/sapi/embed/php_embed.h ${DESTDIR}${PREFIX}/include/php/sapi/embed/
	${INSTALL_LIB} ${WRKSRC}/libs/libphp5.so ${DESTDIR}${PREFIX}/lib/
.endif
