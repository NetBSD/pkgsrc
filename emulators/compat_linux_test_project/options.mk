# $NetBSD: options.mk,v 1.1 2026/10/19 10:12:30 sborrill Exp $
PKG_OPTIONS_VAR=	PKG_OPTIONS.compat_linux_test_project
PKG_SUPPORTED_OPTIONS=	static
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mstatic)
LINK_MODE=		static
.else
LINK_MODE=		dynamic
EMUL_MODULES.linux=	base
.endif
