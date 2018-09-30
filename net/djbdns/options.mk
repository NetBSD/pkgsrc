# $NetBSD: options.mk,v 1.21 2018/09/30 22:10:51 schmonz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.djbdns
PKG_SUPPORTED_OPTIONS+=		# inet6
PKG_SUPPORTED_OPTIONS+=		djbdns-cachestats djbdns-ignoreip2
PKG_SUPPORTED_OPTIONS+=		djbdns-mergequeries djbdns-tinydns64
PKG_SUGGESTED_OPTIONS+=		djbdns-mergequeries djbdns-tinydns64

.include "../../mk/bsd.options.mk"

PLIST_VARS+=			inet6
#.if !empty(PKG_OPTIONS:Minet6)
#IPV6_PATCH=			djbdns-1.05-test28.diff.xz
#PATCHFILES+=			${IPV6_PATCH}
#SITES.${IPV6_PATCH}=		http://www.fefe.de/dns/
#USE_TOOLS+=			xzcat
#PATCH_DIST_CAT.${IPV6_PATCH}=	xzcat < ${IPV6_PATCH}
#PATCH_DIST_STRIP.${IPV6_PATCH}=	-p1
#MAKE_JOBS_SAFE=			no
#PLIST.inet6=			yes
#.endif

.if !empty(PKG_OPTIONS:Mdjbdns-cachestats)
CACHESTATS_PATCH=		djbdns-cachestats.patch
PATCHFILES+=			${CACHESTATS_PATCH}
SITES.${CACHESTATS_PATCH}=	http://romana.now.ie/software/
PATCH_DIST_STRIP.${CACHESTATS_PATCH}= -p1
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
