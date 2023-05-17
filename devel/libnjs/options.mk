# $NetBSD: options.mk,v 1.1 2023/05/17 16:44:51 osa Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libnjs
PKG_SUPPORTED_OPTIONS=	ssl pcre2 xml
PKG_SUGGESTED_OPTIONS=	ssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpcre2)
.include "../../devel/pcre2/buildlink3.mk"
SUBST_CLASSES+=		fix-pcre2
SUBST_STAGE.fix-pcre2=	pre-configure
SUBST_FILES.fix-pcre2=	auto/pcre
SUBST_SED.fix-pcre2=	-e 's,/usr/pkg,${BUILDLINK_PREFIX.pcre2},g'
SUBST_NOOP_OK.fix-pcre2=yes
.else
CONFIGURE_ARGS+=	--no-pcre
CONFIGURE_ARGS+=	--no-pcre2
.endif

.if !empty(PKG_OPTIONS:Mssl)
.include "../../security/openssl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--no-openssl
.endif

.if !empty(PKG_OPTIONS:Mxml)
.include "../../textproc/libxml2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--no-libxml2
.endif
