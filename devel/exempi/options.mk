# $NetBSD: options.mk,v 1.1.1.1 2008/04/12 10:56:18 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.exempi
PKG_SUPPORTED_OPTIONS=	test

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mtest)
CONFIGURE_ARGS+=	--with-boost=${BUILDLINK_PREFIX.boost-libs}
.include "../../devel/boost-libs/buildlink3.mk"

# 2 self tests fail, see https://bugs.freedesktop.org/show_bug.cgi?id=15265
TEST_TARGET=	check
.else
CONFIGURE_ARGS+=	--enable-unittest=no
.endif
