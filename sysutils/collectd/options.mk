# $NetBSD: options.mk,v 1.11 2017/11/21 16:02:20 he Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.collectd
PKG_SUPPORTED_OPTIONS=	cpu df interface load memory syslog uptime
PKG_SUGGESTED_OPTIONS+=	cpu df interface load memory syslog uptime

PKG_SUPPORTED_OPTIONS.NetBSD+=	contextswitch disk entropy irq pf netstat_udp
PKG_SUPPORTED_OPTIONS.NetBSD+=	swap tcpconns users processes
PKG_SUGGESTED_OPTIONS.NetBSD+=	contextswitch disk entropy irq pf netstat_udp
PKG_SUGGESTED_OPTIONS.NetBSD+=	swap tcpconns users processes

PKG_SUPPORTED_OPTIONS.FreeBSD+=	contextswitch pf processes swap tcpconns zfs-arc
PKG_SUGGESTED_OPTIONS.FreeBSD+=	contextswitch pf processes swap tcpconns zfs-arc

PKG_SUPPORTED_OPTIONS.Darwin+=	apple-sensors battery contextswitch disk
PKG_SUPPORTED_OPTIONS.Darwin+=	processes swap tcpconns users
PKG_SUGGESTED_OPTIONS.Darwin+=	apple-sensors battery contextswitch disk
PKG_SUGGESTED_OPTIONS.Darwin+=	processes swap tcpconns users

PKG_SUPPORTED_OPTIONS.SunOS+=	disk nfs swap users zfs-arc zone
PKG_SUGGESTED_OPTIONS.SunOS+=	disk nfs swap users zfs-arc zone

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		apple-sensors battery contextswitch cpu entropy \
			df disk		\
			interface irq load netstat_udp \
			memory nfs pf processes swap	\
			syslog tcpconns uptime users zfs-arc zone

.for option in ${PLIST_VARS}
.  if !empty(PKG_OPTIONS:M${option})
CONFIGURE_ARGS+=	--enable-${option:S/-/_/}
PLIST.${option}=	yes
.  endif
.endfor
