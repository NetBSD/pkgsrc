# $NetBSD: options.mk,v 1.13 2023/12/07 17:05:10 gdt Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.py-anita
PKG_SUPPORTED_OPTIONS=		qemu xen
PKG_SUGGESTED_OPTIONS=

# To run (but not to build), anita needs some way to run a virtual
# machine.  The standard approach is qemu.  An alternate approach is
# xen (when running anita on a dom0).

# By default, py-anita does not depend on any of these, because a
# hypervisor one doesn't want to use is a large burden.  While these
# options can be enabled to cause anita to depend on qemu or xen, they
# also serve to document ways to fulfill the hypervisor requirement.

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mqemu)
DEPENDS+=	qemu>=3:../../emulators/qemu
.endif

# Either 415 or 418 should work; we choose 418 because it's newer.
.if !empty(PKG_OPTIONS:Mxen)
DEPENDS+=	xenkernel418>=4.2:../../sysutils/xenkernel418
DEPENDS+=	xentools418>=4.2:../../sysutils/xentools418
.endif
