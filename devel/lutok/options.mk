# $NetBSD: options.mk,v 1.1 2025/03/30 08:48:24 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.lutok
PKG_SUPPORTED_OPTIONS=	tests
# disabled since kyua depends on lutok
PKG_SUGGESTED_OPTIONS=	#

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	test
.if !empty(PKG_OPTIONS:Mtests)
# this should be a test dependency, but the configure script checks
# for it using pkg-config, so we need the bl3.mk include
BUILDLINK_API_DEPENDS.atf+=	atf>=0.21
.  include "../../devel/atf/buildlink3.mk"
# detected by configure script, so we can't use TEST_DEPENDS
# and kyua depends on lutok...
TOOL_DEPENDS+=	kyua-[0-9]*:../../devel/kyua
CONFIGURE_ARGS+=	--enable-atf
# 97/101 passed (4 failed) as of 0.6.1
TEST_TARGET=	check
PLIST.test=	yes
.else
CONFIGURE_ARGS+=	--disable-atf
.endif
