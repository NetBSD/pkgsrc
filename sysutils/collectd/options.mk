# $NetBSD: options.mk,v 1.12 2020/10/24 22:39:45 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.collectd
PKG_SUPPORTED_OPTIONS=	collectd-cpu collectd-df collectd-interface collectd-load collectd-memory collectd-syslog collectd-uptime
PKG_SUPPORTED_OPTIONS+=	collectd-multimeter collectd-ted
PKG_SUGGESTED_OPTIONS=	collectd-cpu collectd-df collectd-interface collectd-load collectd-memory collectd-syslog collectd-uptime
PKG_SUGGESTED_OPTIONS+=	collectd-multimeter collectd-ted

PKG_SUPPORTED_OPTIONS.NetBSD+=	collectd-contextswitch collectd-disk collectd-entropy collectd-irq collectd-pf collectd-netstat-udp
PKG_SUPPORTED_OPTIONS.NetBSD+=	collectd-swap collectd-tcpconns collectd-users collectd-processes collectd-nfs
PKG_SUGGESTED_OPTIONS.NetBSD+=	collectd-contextswitch collectd-disk collectd-entropy collectd-irq collectd-pf collectd-netstat-udp
PKG_SUGGESTED_OPTIONS.NetBSD+=	collectd-swap collectd-tcpconns collectd-users collectd-processes collectd-nfs

PKG_SUPPORTED_OPTIONS.FreeBSD+=	collectd-contextswitch collectd-pf collectd-processes collectd-swap collectd-tcpconns collectd-zfs-arc
PKG_SUGGESTED_OPTIONS.FreeBSD+=	collectd-contextswitch collectd-pf collectd-processes collectd-swap collectd-tcpconns collectd-zfs-arc

PKG_SUPPORTED_OPTIONS.Darwin+=	collectd-apple-sensors collectd-battery collectd-contextswitch collectd-disk
PKG_SUPPORTED_OPTIONS.Darwin+=	collectd-processes collectd-swap collectd-tcpconns collectd-users
PKG_SUGGESTED_OPTIONS.Darwin+=	collectd-apple-sensors collectd-battery collectd-contextswitch collectd-disk
PKG_SUGGESTED_OPTIONS.Darwin+=	collectd-processes collectd-swap collectd-tcpconns collectd-users

PKG_SUPPORTED_OPTIONS.SunOS+=	collectd-disk collectd-nfs collectd-swap collectd-users collectd-zfs-arc collectd-zone
PKG_SUGGESTED_OPTIONS.SunOS+=	collectd-disk collectd-nfs collectd-swap collectd-users collectd-zfs-arc collectd-zone

PKG_SUPPORTED_OPTIONS+=		collectd-debug

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		collectd-apple-sensors collectd-battery collectd-contextswitch collectd-cpu collectd-entropy \
			collectd-df collectd-disk \
			collectd-interface collectd-irq collectd-load collectd-netstat-udp \
			collectd-memory collectd-nfs collectd-pf collectd-processes collectd-swap \
			collectd-syslog collectd-tcpconns collectd-uptime collectd-users collectd-zfs-arc collectd-zone \
			collectd-multimeter collectd-ted

.for option in ${PLIST_VARS}
.  if !empty(PKG_OPTIONS:M${option})
CONFIGURE_ARGS+=	--enable-${option:S/collectd-//:S/-/_/}
PLIST.${option}=	yes
.  endif
.endfor

.if !empty(PKG_OPTIONS:Mcollectd-debug)
CONFIGURE_ARGS+=	--enable-debug
.endif
