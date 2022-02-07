# $NetBSD: options.mk,v 1.3 2022/02/07 02:26:09 gutteridge Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.${PHP_PKG_PREFIX}
PKG_SUPPORTED_OPTIONS+=		inet6 ssl zts readline argon2 php-embed
PKG_SUPPORTED_OPTIONS+=		disable-filter-url
PKG_SUGGESTED_OPTIONS+=		inet6 ssl readline
PKG_OPTIONS_LEGACY_OPTS+=	maintainer-zts:zts

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

.if !empty(PKG_OPTIONS:Mzts)
CONFIGURE_ARGS+=	--enable-zts
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

PLIST_VARS+=	embed

.if !empty(PKGNAME:Mphp-[7-9]*)
.  if !empty(PKG_OPTIONS:Mphp-embed)
CONFIGURE_ARGS+=	--enable-embed
INSTALLATION_DIRS+=	include/php/sapi/embed
PLIST.embed=		yes

.PHONY: post-install-embed
post-install: post-install-embed
post-install-embed:
	${INSTALL_DATA} ${WRKSRC}/sapi/embed/php_embed.h ${DESTDIR}${PREFIX}/include/php/sapi/embed/
	${INSTALL_LIB} ${WRKSRC}/libs/libphp.so ${DESTDIR}${PREFIX}/lib/
.  endif
.endif
