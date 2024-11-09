# $NetBSD: options.mk,v 1.3 2024/11/09 15:59:32 js Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.fossil
PKG_SUPPORTED_OPTIONS=	fossil-th1-hooks json openssl tcl
PKG_SUGGESTED_OPTIONS=	openssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mfossil-th1-hooks)
CONFIGURE_ARGS+=	--with-th1-hooks
.endif

.if !empty(PKG_OPTIONS:Mjson)
CONFIGURE_ARGS+=	--json
.endif

.if !empty(PKG_OPTIONS:Mopenssl)
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl:Q}
.include "../../security/openssl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--with-openssl=none
.endif

.if !empty(PKG_OPTIONS:Mtcl)
CONFIGURE_ARGS+=	--with-tcl
CONFIGURE_ARGS+=	--with-tcl-private-stubs
.include "../../lang/tcl/buildlink3.mk"
.endif
