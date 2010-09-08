# $NetBSD: options.mk,v 1.2 2010/09/08 16:45:40 drochner Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.dvdrip
.if !empty(MACHINE_ARCH:Mi386)
PKG_SUPPORTED_OPTIONS=	rar

#PKG_SUGGESTED_OPTIONS=	rar
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mrar)
DEPENDS+=	{rar,rar-bin}-[0-9]*:../../archivers/rar
.endif
