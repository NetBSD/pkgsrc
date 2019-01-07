# $NetBSD: options.mk,v 1.2 2019/01/07 14:01:55 schmonz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.djbdns-run
PKG_SUPPORTED_OPTIONS+=	inet6

.include "../../mk/bsd.options.mk"

FILES_SUBST+=		TINYDNS_LISTENIP=${TINYDNS_LISTENIP:Q}
FILES_SUBST+=		DNSCACHE_LISTENIP=${DNSCACHE_LISTENIP:Q}
FILES_SUBST+=		DNSCACHE_SENDIP=${DNSCACHE_SENDIP:Q}

.if !empty(PKG_OPTIONS:Minet6)
DEPENDS_DJBDNS=		djbdnscurve6-[0-9]*:../../net/djbdnscurve6
DEPENDS+=		ucspi-tcp6-[0-9]*:../../net/ucspi-tcp6
TINYDNS_LISTENIP=	::
DNSCACHE_LISTENIP=	::1
DNSCACHE_SENDIP=	::
CONF_FILES+=		${PREFIX}/share/examples/${PKGBASE}/dnscache-ip \
			${PKG_SYSCONFDIR}/dnscache/ip/::1
.else
DEPENDS_DJBDNS=		djbdns>=1.05nb5:../../net/djbdns
DEPENDS+=		ucspi-tcp-[0-9]*:../../net/ucspi-tcp
TINYDNS_LISTENIP=	0.0.0.0
DNSCACHE_LISTENIP=	127.0.0.1
DNSCACHE_SENDIP=	0.0.0.0
CONF_FILES+=		${PREFIX}/share/examples/${PKGBASE}/dnscache-ip \
			${PKG_SYSCONFDIR}/dnscache/ip/127.0.0.1
.endif
