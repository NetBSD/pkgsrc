# $NetBSD: options.mk,v 1.4 2011/12/05 17:52:37 gdt Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.quagga
PKG_SUPPORTED_OPTIONS=	inet6
PKG_SUPPORTED_OPTIONS+=	quagga-ospf-opaque-lsa
PKG_SUGGESTED_OPTIONS+=	quagga-ospf-opaque-lsa
PKG_SUPPORTED_OPTIONS+=	quagga-vtysh
PKG_SUGGESTED_OPTIONS+=	quagga-vtysh

PKG_OPTIONS_LEGACY_VARS+=	USE_ZEBRA_OSPF_OPAQUELSA:quagga-ospf-opaque-lsa
PKG_OPTIONS_LEGACY_VARS+=	USE_ZEBRA_VTYSH:quagga-vtysh

.include "../../mk/bsd.options.mk"

###
### IPv6 support
###
.if !empty(PKG_OPTIONS:Minet6)
PLIST_CAT+=		${PKGDIR}/PLIST.v6
RCD_SCRIPTS+=		ospf6d ripngd
.  for _file_ in ospf6d.conf ripngd.conf
CONF_FILES_PERMS+=	${PREFIX}/share/examples/quagga/log_syslog.conf	\
			${PKG_SYSCONFDIR}/${_file_} quagga quagga 0600
.  endfor
.else
CONFIGURE_ARGS+=	--disable-ospf6d
CONFIGURE_ARGS+=	--disable-ripngd
.endif

###
### Include 'vtysh' program.
###
.if !empty(PKG_OPTIONS:Mquagga-vtysh)
USE_GNU_READLINE=	# uses rl_pending_input
.  include "../../devel/readline/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-vtysh
PLIST_CAT+=		${PKGDIR}/PLIST.vtysh
.else
CONFIGURE_ARGS+=	--disable-vtysh
.endif

###
### Include Opaque LSA support in OSPF (RFC2370).
###
.if !empty(PKG_OPTIONS:Mquagga-ospf-opaque-lsa)
# opaque-lsa is now the upstream default.
PLIST_CAT+=		${PKGDIR}/PLIST.opaquelsa
.else
CONFIGURE_ARGS+=	--disable-opaque-lsa
.endif
