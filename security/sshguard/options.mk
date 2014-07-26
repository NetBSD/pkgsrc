# $NetBSD: options.mk,v 1.1 2014/07/26 19:57:44 tron Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.sshguard
PKG_OPTIONS_REQUIRED_GROUPS=	firewall
PKG_OPTIONS_GROUP.firewall=	sshguard-aix sshguard-hosts sshguard-ipfilter \
				sshguard-ipfw sshguard-iptables sshguard-null \
				sshguard-pf

.include "../../mk/bsd.prefs.mk"

# Pick an appropriate default firewall depending on the platform. We however
# don't restrict the firewall types. You can e.g. use "iptables" under NetBSD
# to remotely manage a Linux firewall.
.if ${OPSYS} == "AIX"
PKG_SUGGESTED_OPTIONS=		sshguard-aix
.elif ${OPSYS} == "Darwin"
PKG_SUGGESTED_OPTIONS=		sshguard-ipfw
.elif ${OPSYS} == "DragonFly"
PKG_SUGGESTED_OPTIONS=		sshguard-pf
.elif ${OPSYS} == "Linux"
PKG_SUGGESTED_OPTIONS=		sshguard-iptables
.elif ${OPSYS} == "FreeBSD"
PKG_SUGGESTED_OPTIONS=		sshguard-ipfw
.elif ${OPSYS} == "NetBSD"
PKG_SUGGESTED_OPTIONS=		sshguard-ipfilter
.elif ${OPSYS} == "OpenBSD"
PKG_SUGGESTED_OPTIONS=		sshguard-pf
.elif ${OPSYS} == "SunOS"
PKG_SUGGESTED_OPTIONS=		sshguard-ipfilter
.else
PKG_SUGGESTED_OPTIONS=		sshguard-hosts
.endif

.include "../../mk/bsd.options.mk"

# Pick the desire firewall backend
.if !empty(PKG_OPTIONS:Msshguard-aix)
CONFIGURE_ARGS+=	--with-firewall=aix
.elif !empty(PKG_OPTIONS:Msshguard-hosts)
CONFIGURE_ARGS+=	--with-firewall=hosts
.elif !empty(PKG_OPTIONS:Msshguard-ipfilter)
CONFIGURE_ARGS+=	--with-firewall=ipfilter
# Set correct location of IPFilter configuration file under NetBSD.
.  if ${OPSYS} == "NetbSD"
CONFIGURE_ARGS+=	--with-ipfilterconf=/etc/ipf.conf
.  endif
.elif !empty(PKG_OPTIONS:Msshguard-ipfw)
CONFIGURE_ARGS+=	--with-firewall=ipfw
.elif !empty(PKG_OPTIONS:Msshguard-iptables)
CONFIGURE_ARGS+=	--with-firewall=iptables
.elif !empty(PKG_OPTIONS:Msshguard-null)
CONFIGURE_ARGS+=	--with-firewall=null
.elif !empty(PKG_OPTIONS:Msshguard-pf)
CONFIGURE_ARGS+=	--with-firewall=pf
.endif
