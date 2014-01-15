# $NetBSD: options.mk,v 1.1 2014/01/15 19:05:34 martin Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.py-anita
PKG_SUPPORTED_OPTIONS=		qemu-0
PKG_SUGGESTED_OPTIONS=		qemu-0

.include "../../mk/bsd.options.mk"

# qemu1 does not work reliably.  See the anita(1) man page.
.if empty(PKG_OPTIONS:Mqemu-0)
DEPENDS+=	qemu:../../emulators/qemu
.  include "../../lang/lua/buildlink3.mk"
.else
DEPENDS+=	qemu>=0.12.3nb2:../../emulators/qemu0
.endif
