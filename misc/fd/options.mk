# $NetBSD: options.mk,v 1.2 2011/04/08 11:34:44 obache Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.fd
PKG_SUPPORTED_OPTIONS=		fd-small

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	fd-full

.if !empty(PKG_OPTIONS:Mfd-small)
MAKE_FLAGS+=	VERSION=1
FD_CONFIG=	fdrc
.else
FD_CONFIG=	fd2rc
PLIST.fd-full=	yes
.endif
