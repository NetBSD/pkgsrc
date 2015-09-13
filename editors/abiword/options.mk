# $NetBSD: options.mk,v 1.1 2015/09/13 21:32:13 nros Exp $

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

