# $NetBSD: options.mk,v 1.2 2004/11/17 19:56:49 xtraeme Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.djbdns
PKG_SUPPORTED_OPTIONS=	inet6 ignoreip2
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
