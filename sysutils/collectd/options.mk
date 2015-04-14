# $NetBSD: options.mk,v 1.2 2015/04/14 11:27:30 fhajny Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.collectd
PKG_SUPPORTED_OPTIONS=	cpu df interface load memory syslog uptime
PKG_SUGGESTED_OPTIONS+=	cpu df interface load memory syslog uptime

.if ${OPSYS} == "NetBSD"
PKG_SUPPORTED_OPTIONS+=	contextswitch pf tcpconns users
PKG_SUGGESTED_OPTIONS+=	contextswitch pf tcpconns users
.endif

.if ${OPSYS} == "FreeBSD"
PKG_SUPPORTED_OPTIONS+=	contextswitch pf processes swap tcpconns zfs-arc
PKG_SUGGESTED_OPTIONS+=	contextswitch pf processes swap tcpconns zfs-arc
.endif

.if ${OPSYS} == "Darwin"
PKG_SUPPORTED_OPTIONS+=	apple-sensors battery contextswitch disk processes swap	\
			tcpconns users
PKG_SUGGESTED_OPTIONS+=	apple-sensors battery contextswitch disk processes swap	\
			tcpconns users
.endif

.if ${OPSYS} == "SunOS"
PKG_SUPPORTED_OPTIONS+=	disk nfs swap users zfs-arc
PKG_SUGGESTED_OPTIONS+=	disk nfs swap users zfs-arc
.endif

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		apple-sensors battery contextswitch cpu df disk		\
			interface load memory nfs pf processes swap	\
			syslog tcpconns uptime users zfs-arc

.for option in ${PLIST_VARS}
.  if !empty(PKG_OPTIONS:M${option})
CONFIGURE_ARGS+=	--enable-${option:S/-/_/}
PLIST.${option}=	yes
.  endif
.endfor
