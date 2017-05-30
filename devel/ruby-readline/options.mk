# $NetBSD: options.mk,v 1.8 2017/05/30 14:19:51 taca Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.ruby
PKG_SUPPORTED_OPTIONS=	readline ruby-build-ri-db
PKG_SUGGESTED_OPTIONS=	ruby-build-ri-db readline

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mreadline)
READLINE_DEFAULT?=	readline
.endif
.include "../../mk/readline.buildlink3.mk"

.if ${READLINE_TYPE} == "editline"
CONFIGURE_ARGS+=	--enable-libedit
.else
CONFIGURE_ARGS+=	--disable-libedit
.endif
