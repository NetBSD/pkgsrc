# $NetBSD: options.mk,v 1.26 2021/11/15 20:30:32 schmonz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.djbdns
PKG_SUPPORTED_OPTIONS+=		djbdns-cachestats djbdns-ignoreip2 djbdns-listenmultiple
PKG_SUPPORTED_OPTIONS+=		djbdns-mergequeries djbdns-tinydns64
PKG_SUGGESTED_OPTIONS+=		djbdns-mergequeries djbdns-tinydns64

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdjbdns-cachestats)
CACHESTATS_PATCH=			djbdns-cachestats.patch
PATCHFILES+=				${CACHESTATS_PATCH}
SITES.${CACHESTATS_PATCH}=		https://lecter.redbrick.dcu.ie/software/
PATCH_DIST_STRIP.${CACHESTATS_PATCH}=	-p1
.endif

.if !empty(PKG_OPTIONS:Mdjbdns-ignoreip2)
IGNOREIP2_PATCH=		djbdns-1.05-ignoreip2.patch
PATCHFILES+=			${IGNOREIP2_PATCH}
SITES.${IGNOREIP2_PATCH}=	${MASTER_SITE_LOCAL}
.endif

.if !empty(PKG_OPTIONS:Mdjbdns-mergequeries)
USE_TOOLS+=			patch
post-patch: patch-mergequeries
.PHONY: patch-mergequeries
patch-mergequeries:
	cd ${WRKSRC} && ${PATCH} ${PATCH_ARGS} < ${FILESDIR}/patch-mergequeries
	cd ${WRKSRC} && ${PATCH} ${PATCH_ARGS} < ${FILESDIR}/patch-mergequeries-boundscheck
.endif

.if !empty(PKG_OPTIONS:Mdjbdns-listenmultiple)
TINYMULTI_PATCH=			djbdns-1.05-multiip.diff
CACHEMULTI_PATCH=			dnscache-1.05-multiple-ip.patch
PATCHFILES+=				${TINYMULTI_PATCH} ${CACHEMULTI_PATCH}
SITES.${TINYMULTI_PATCH}=		https://ohse.de/uwe/patches/
SITES.${CACHEMULTI_PATCH}=		${MASTER_SITE_LOCAL}
PATCH_DIST_STRIP.${TINYMULTI_PATCH}=	-p1
PATCH_DIST_STRIP.${CACHEMULTI_PATCH}=	-p1
BUILD_DEFS+=				DJBDNS_IP_SEPARATOR
PATCH_DIST_CAT.${TINYMULTI_PATCH}=	${SED} -e "s|','|'${DJBDNS_IP_SEPARATOR}'|g" \
					< ${TINYMULTI_PATCH}
PATCH_DIST_CAT.${CACHEMULTI_PATCH}=	${SED} -e "s|'/'|'${DJBDNS_IP_SEPARATOR}'|g" \
					< ${CACHEMULTI_PATCH}
.endif

.if !empty(PKG_OPTIONS:Mdjbdns-tinydns64)
USE_TOOLS+=			patch
post-patch: patch-tinydns64
.PHONY: patch-tinydns64
patch-tinydns64:
	cd ${WRKSRC} && ${PATCH} ${PATCH_ARGS} < ${FILESDIR}/patch-tinydns64
.endif
