# $NetBSD: options.mk,v 1.3 2025/08/30 08:24:18 pho Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.gkrellm
PKG_SUPPORTED_OPTIONS=		nls ntlm
PKG_OPTIONS_OPTIONAL_GROUPS=	tls
PKG_OPTIONS_GROUP.tls=		gnutls openssl
PKG_SUGGESTED_OPTIONS+=		nls ntlm openssl
PKG_OPTIONS_LEGACY_OPTS+=	ssl:openssl

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == "Darwin"
PKG_SUPPORTED_OPTIONS+=	quartz
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mnls)
.  include "../../devel/gettext-lib/buildlink3.mk"
MAKE_FLAGS+=	enable_nls=1
.endif

.if !empty(PKG_OPTIONS:Mntlm)
.  include "../../devel/libntlm/buildlink3.mk"
.else
MAKE_FLAGS+=	without-ntlm=yes
.endif

.if !empty(PKG_OPTIONS:Mopenssl)
.  include "../../security/openssl/buildlink3.mk"
.else
MAKE_FLAGS+=	without-ssl=yes
.endif

.if !empty(PKG_OPTIONS:Mgnutls)
.  include "../../security/gnutls/buildlink3.mk"
.else
MAKE_FLAGS+=	without-gnutls=yes
.endif

.if !empty(PKG_OPTIONS:Mquartz)
# Handled in Makefile.common
.else
.  include "../../x11/libICE/buildlink3.mk"
.  include "../../x11/libSM/buildlink3.mk"
.endif
