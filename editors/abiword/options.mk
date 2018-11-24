# $NetBSD: options.mk,v 1.3 2018/11/24 19:14:09 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.abiword
PKG_SUPPORTED_OPTIONS=		debug
.include "../../mk/bsd.options.mk"

#
# Enable debugging funcionality
# more verbose terminal output
#
.if !empty(PKG_OPTIONS:Mdebug)
CC+=			-ggdb
CXX+=			-ggdb
CONFIGURE_ARGS+=        --enable-debug
INSTALL_UNSTRIPPED=	yes
CFLAGS+=		-O0
.endif

