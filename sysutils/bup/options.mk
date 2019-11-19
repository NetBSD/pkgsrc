# $NetBSD: options.mk,v 1.2 2019/11/19 15:01:25 gdt Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.bup
PKG_SUPPORTED_OPTIONS=	fuse
# fuse is disabled by default because it doesn't build on Mac, and
# because the fuse implementation in bup doesn't work on NetBSD.
# After it's fixed upstream, an OS-specific default is probably
# appropriate.
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.prefs.mk"

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mfuse)
.include "../../filesystems/py-fuse-bindings/buildlink3.mk"
.endif
