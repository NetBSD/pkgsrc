# $NetBSD: options.mk,v 1.5 2021/08/27 07:55:36 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.unbound
PKG_SUPPORTED_OPTIONS+=	dnstap doh
PKG_SUGGESTED_OPTIONS+=	doh

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdnstap)
CONFIGURE_ARGS+=	--enable-dnstap
.include "../../net/fstrm/buildlink3.mk"
.include "../../devel/protobuf/buildlink3.mk"
.include "../../devel/protobuf-c/buildlink3.mk"
.endif

# DNS-over-HTTPS
.if !empty(PKG_OPTIONS:Mdoh)
.include "../../www/nghttp2/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libnghttp2=${BUILDLINK_PREFIX.nghttp2}
.endif
