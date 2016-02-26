# $NetBSD: options.mk,v 1.2 2016/02/26 09:41:07 jperkin Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.sshguard
PKG_OPTIONS_REQUIRED_GROUPS=	firewall
PKG_OPTIONS_GROUP.firewall=	sshguard-aix sshguard-hosts sshguard-ipfilter \
				sshguard-ipfw sshguard-iptables sshguard-null \
				sshguard-pf

.include "../../mk/bsd.prefs.mk"

# Pick an appropriate default firewall depending on the platform. We however
# don't restrict the firewall types. You can e.g. use "iptables" under NetBSD
# to remotely manage a Linux firewall.
PKG_SUGGESTED_OPTIONS.AIX=		sshguard-aix
PKG_SUGGESTED_OPTIONS.Darwin=		sshguard-ipfw
PKG_SUGGESTED_OPTIONS.DragonFly=	sshguard-pf
PKG_SUGGESTED_OPTIONS.FreeBSD=		sshguard-ipfw
PKG_SUGGESTED_OPTIONS.Linux=		sshguard-iptables
PKG_SUGGESTED_OPTIONS.NetBSD=		sshguard-ipfilter
PKG_SUGGESTED_OPTIONS.OpenBSD=		sshguard-pf
PKG_SUGGESTED_OPTIONS.SunOS=		sshguard-ipfilter
PKG_SUGGESTED_OPTIONS.*=		sshguard-hosts

.include "../../mk/bsd.options.mk"

# Pick the desire firewall backend
.if !empty(PKG_OPTIONS:Msshguard-aix)
CONFIGURE_ARGS+=	--with-firewall=aix
.elif !empty(PKG_OPTIONS:Msshguard-hosts)
CONFIGURE_ARGS+=	--with-firewall=hosts
.elif !empty(PKG_OPTIONS:Msshguard-ipfilter)
CONFIGURE_ARGS+=	--with-firewall=ipfilter
# Set correct location of IPFilter configuration file under NetBSD.
CONFIGURE_ARGS.NetBSD+=	--with-ipfilterconf=/etc/ipf.conf
.elif !empty(PKG_OPTIONS:Msshguard-ipfw)
CONFIGURE_ARGS+=	--with-firewall=ipfw
.elif !empty(PKG_OPTIONS:Msshguard-iptables)
CONFIGURE_ARGS+=	--with-firewall=iptables
.elif !empty(PKG_OPTIONS:Msshguard-null)
CONFIGURE_ARGS+=	--with-firewall=null
.elif !empty(PKG_OPTIONS:Msshguard-pf)
CONFIGURE_ARGS+=	--with-firewall=pf
.endif
