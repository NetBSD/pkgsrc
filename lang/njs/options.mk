# $NetBSD: options.mk,v 1.2 2022/07/14 10:59:51 osa Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.njs
PKG_SUPPORTED_OPTIONS=	pcre pcre2 ssl
PKG_SUGGESTED_OPTIONS=	pcre ssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpcre)
.include "../../devel/pcre/buildlink3.mk"
SUBST_CLASSES+=		fix-pcre
SUBST_STAGE.fix-pcre=	pre-configure
SUBST_FILES.fix-pcre=	auto/pcre
SUBST_SED.fix-pcre=	-e 's,/usr/pkg,${BUILDLINK_PREFIX.pcre},g'
SUBST_NOOP_OK.fix-pcre=	yes
.else
CONFIGURE_ARGS+=	--no-pcre2
.endif

.if !empty(PKG_OPTIONS:Mpcre2)
.include "../../devel/pcre2/buildlink3.mk"
SUBST_CLASSES+=		fix-pcre2
SUBST_STAGE.fix-pcre2=	pre-configure
SUBST_FILES.fix-pcre2=	auto/pcre
SUBST_SED.fix-pcre2=	-e 's,/usr/pkg,${BUILDLINK_PREFIX.pcre2},g'
SUBST_NOOP_OK.fix-pcre2=yes
.endif

.if empty(PKG_OPTIONS:Mpcre2) && empty(PKG_OPTIONS:Mpcre)
PKG_FAIL_REASON=	"Requires PCRE or PCRE2."
.endif

.if !empty(PKG_OPTIONS:Mssl)
.include "../../security/openssl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--no-openssl
.endif
