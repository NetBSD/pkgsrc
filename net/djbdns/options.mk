# $NetBSD: options.mk,v 1.23 2019/11/03 11:45:33 rillig Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.djbdns
PKG_SUPPORTED_OPTIONS+=		djbdns-cachestats djbdns-ignoreip2
PKG_SUPPORTED_OPTIONS+=		djbdns-mergequeries djbdns-tinydns64
PKG_SUGGESTED_OPTIONS+=		djbdns-mergequeries djbdns-tinydns64

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdjbdns-cachestats)
CACHESTATS_PATCH=			djbdns-cachestats.patch
PATCHFILES+=				${CACHESTATS_PATCH}
SITES.${CACHESTATS_PATCH}=		http://romana.now.ie/software/
PATCH_DIST_STRIP.${CACHESTATS_PATCH}=	-p1
.endif

.if !empty(PKG_OPTIONS:Mdjbdns-ignoreip2)
IGNOREIP2_PATCH=		djbdns-1.05-ignoreip2.patch
PATCHFILES+=			${IGNOREIP2_PATCH}
SITES.${IGNOREIP2_PATCH}=	http://www.tinydns.org/
.endif

.if !empty(PKG_OPTIONS:Mdjbdns-mergequeries)
USE_TOOLS+=			patch
post-patch: patch-mergequeries
.PHONY: patch-mergequeries
patch-mergequeries:
	cd ${WRKSRC} && ${PATCH} ${PATCH_ARGS} < ${FILESDIR}/patch-mergequeries
	cd ${WRKSRC} && ${PATCH} ${PATCH_ARGS} < ${FILESDIR}/patch-mergequeries-boundscheck
.endif

.if !empty(PKG_OPTIONS:Mdjbdns-tinydns64)
USE_TOOLS+=			patch
post-patch: patch-tinydns64
.PHONY: patch-tinydns64
patch-tinydns64:
	cd ${WRKSRC} && ${PATCH} ${PATCH_ARGS} < ${FILESDIR}/patch-tinydns64
.endif
