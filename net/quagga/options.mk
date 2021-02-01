# $NetBSD: options.mk,v 1.10 2021/02/01 20:51:24 gdt Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.quagga
PKG_SUPPORTED_OPTIONS=	inet6
PKG_SUPPORTED_OPTIONS+=	quagga-vtysh
PKG_SUGGESTED_OPTIONS=	inet6
PKG_SUGGESTED_OPTIONS+=	quagga-vtysh

.include "../../mk/bsd.options.mk"

###
### IPv6 support
###
.if !empty(PKG_OPTIONS:Minet6)
PLIST_CAT+=		${PKGDIR}/PLIST.v6
RCD_SCRIPTS+=		ospf6d ripngd
.  for file in ospf6d.conf ripngd.conf
CONF_FILES_PERMS+=	${PREFIX}/share/examples/quagga/log_syslog.conf	\
			${PKG_SYSCONFDIR}/${file} quagga quagga 0600
.  endfor
.else
CONFIGURE_ARGS+=	--disable-ospf6d
CONFIGURE_ARGS+=	--disable-ripngd
.endif

###
### Include 'vtysh' program.
###
.if !empty(PKG_OPTIONS:Mquagga-vtysh)
# uses rl_pending_input
.  include "../../devel/readline/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-vtysh
PLIST_CAT+=		${PKGDIR}/PLIST.vtysh
.else
CONFIGURE_ARGS+=	--disable-vtysh
.endif
