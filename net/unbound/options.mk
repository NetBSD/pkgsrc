# $NetBSD: options.mk,v 1.3 2019/01/17 14:19:51 he Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.unbound
PKG_SUPPORTED_OPTIONS+=	dnstap
# PKG_SUGGESTED_OPTIONS+=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdnstap)
CONFIGURE_ARGS+=	--enable-dnstap
.include "../../net/fstrm/buildlink3.mk"
.include "../../devel/protobuf/buildlink3.mk"
.include "../../devel/protobuf-c/buildlink3.mk"
.endif
