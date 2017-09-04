# $NetBSD: options.mk,v 1.2 2017/09/04 09:40:57 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.exempi
PKG_SUPPORTED_OPTIONS=	test

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mtest)
CONFIGURE_ARGS+=	--with-boost=${BUILDLINK_PREFIX.boost-libs}
.include "../../devel/boost-libs/buildlink3.mk"
TEST_TARGET=	check
.else
CONFIGURE_ARGS+=	--enable-unittest=no
.endif
