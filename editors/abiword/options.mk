# $NetBSD: options.mk,v 1.4 2019/06/08 10:40:53 rillig Exp $

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
CONFIGURE_ARGS+=	--enable-debug
INSTALL_UNSTRIPPED=	yes
CFLAGS+=		-O0
.endif

