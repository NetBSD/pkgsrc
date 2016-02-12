# $NetBSD: options.mk,v 1.2 2016/02/12 23:42:15 jperkin Exp $

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
