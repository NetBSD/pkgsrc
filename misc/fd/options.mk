# $NetBSD: options.mk,v 1.1 2006/12/06 15:36:32 taca Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.fd
PKG_SUPPORTED_OPTIONS=		fd-small

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mfd-small)
MAKE_ENV+=	VERSION=1
FD_CONFIG=	fdrc
.else
FD_CONFIG=	fd2rc
.endif
