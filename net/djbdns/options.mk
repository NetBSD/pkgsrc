# $NetBSD: options.mk,v 1.3 2005/03/30 10:00:36 schmonz Exp $

.if ${MACHINE_ARCH} == "sparc64" || \
	${MACHINE_ARCH} == "alpha" || \
	${MACHINE_ARCH} == "amd64"
PKG_DEFAULT_OPTIONS+=   tinydns64
.endif

PKG_OPTIONS_VAR=	PKG_OPTIONS.djbdns
PKG_SUPPORTED_OPTIONS=	inet6 ignoreip2 tinydns64
.include "../../mk/bsd.options.mk"

###
### Felix von Leitner's IPv6 patch
###
.if !empty(PKG_OPTIONS:Minet6)
IPV6_PATCH=			djbdns-1.05-ipv6.diff.bz2
PATCHFILES+=			${IPV6_PATCH}
SITES_${IPV6_PATCH}=		http://www.fefe.de/dns/
PATCH_DIST_STRIP.${IPV6_PATCH}=	-p1
PLIST_SRC+=			${PKGDIR}/PLIST.inet6
.endif

###
### Russ Nelson's patch to treat certain responses as NXDOMAIN
###
.if !empty(PKG_OPTIONS:Mignoreip2)
IGNOREIP2_PATCH=		djbdns-1.05-ignoreip2.patch
PATCHFILES+=			${IGNOREIP2_PATCH}
SITES_${IGNOREIP2_PATCH}=	http://www.tinydns.org/
.endif

###
### Bernhard Roth's patch to fix tinydns-data on 64-bit platforms
###
.if !empty(PKG_OPTIONS:Mtinydns64)
TINYDNS64_PATCH=		tinydns64.diff
PATCHFILES+=			${TINYDNS64_PATCH}
SITES_${TINYDNS64_PATCH}=	http://www.pwrlock.de/br/
.endif
