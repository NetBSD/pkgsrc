# $NetBSD: options.mk,v 1.8 2005/10/05 05:46:54 schmonz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.djbdns
PKG_SUPPORTED_OPTIONS+=	inet6 djbdns-ignoreip2 djbdns-tinydns64

.if ${MACHINE_ARCH} == "sparc64" || \
	${MACHINE_ARCH} == "alpha" || \
	${MACHINE_ARCH} == "amd64"
PKG_SUGGESTED_OPTIONS+=   djbdns-tinydns64
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
IPV6_PATCH=			djbdns-1.05-ipv6.diff.bz2
PATCHFILES+=			${IPV6_PATCH}
SITES_${IPV6_PATCH}=		http://www.fefe.de/dns/
PATCH_DIST_STRIP.${IPV6_PATCH}=	-p1
PLIST_SRC+=			${PKGDIR}/PLIST.inet6
.endif

.if !empty(PKG_OPTIONS:Mdjbdns-ignoreip2)
IGNOREIP2_PATCH=		djbdns-1.05-ignoreip2.patch
PATCHFILES+=			${IGNOREIP2_PATCH}
SITES_${IGNOREIP2_PATCH}=	http://www.tinydns.org/
.endif

.if !empty(PKG_OPTIONS:Mdjbdns-tinydns64)
TINYDNS64_PATCH=		tinydns64.diff
PATCHFILES+=			${TINYDNS64_PATCH}
SITES_${TINYDNS64_PATCH}=	http://www.pwrlock.de/br/
.endif
