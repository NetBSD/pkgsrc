# $NetBSD: options.mk,v 1.1 2014/01/08 14:59:15 ryoon Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.starbug1
PKG_OPTIONS_REQUIRED_GROUPS=	lang
PKG_OPTIONS_GROUP.lang=		lang-en lang-ja lang-zh-cn
PKG_SUGGESTED_OPTIONS=	lang-en

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlang-en)
BUILD_MAKE_FLAGS=	INITIAL_LOCALE=en_US
.endif

.if !empty(PKG_OPTIONS:Mlang-ja)
BUILD_MAKE_FLAGS=	INITIAL_LOCALE=ja_JP
.endif

.if !empty(PKG_OPTIONS:Mlang-zh-cn)
BUILD_MAKE_FLAGS=	INITIAL_LOCALE=zh_CN
.endif
