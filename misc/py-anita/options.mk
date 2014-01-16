# $NetBSD: options.mk,v 1.3 2014/01/16 13:48:26 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.py-anita
PKG_SUPPORTED_OPTIONS=		qemu-0
PKG_SUGGESTED_OPTIONS=		qemu-0

.include "../../mk/bsd.options.mk"

# qemu1 does not work reliably.  See the anita(1) man page.
.if empty(PKG_OPTIONS:Mqemu-0)
DEPENDS+=	qemu>=1.0:../../emulators/qemu
.else
DEPENDS+=	qemu>=0.12.3nb2:../../emulators/qemu0
.endif
