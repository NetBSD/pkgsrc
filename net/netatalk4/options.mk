# $NetBSD: options.mk,v 1.2 2025/01/12 16:13:10 hauke Exp $
#
PKG_OPTIONS_VAR=		PKG_OPTIONS.netatalk
PKG_SUPPORTED_OPTIONS=		debug dnssd kerberos ldap pam
# Untested
#PKG_SUPPORTED_OPTIONS+=	spotlight
PKG_SUGGESTED_OPTIONS=		dnssd pam

.include "../../mk/bsd.fast.prefs.mk"

# Requires AppleTalk kernel support
.if ${OPSYS} == "Linux" || ${OPSYS} == "NetBSD"
PKG_SUPPORTED_OPTIONS+=		appletalk
PKG_SUGGESTED_OPTIONS+=		appletalk
.endif

.include "../../mk/bsd.options.mk"

PLIST_VARS+=			appletalk gssapi ldap pam spotlight

.if !empty(PKG_OPTIONS:Mappletalk)
# For AppleTalk pap
.include "../../print/cups-base/buildlink3.mk"
PLIST.appletalk=	yes
MESON_ARGS+=		-Dwith-appletalk=true
MESON_ARGS+=		-Dwith-spooldir=${VARBASE}/spool/netatalk
CONF_FILES+=		${EGDIR}/atalkd.conf	${PKG_SYSCONFDIR}/atalkd.conf
CONF_FILES+=		${EGDIR}/papd.conf	${PKG_SYSCONFDIR}/papd.conf
RCD_SCRIPTS+=		${ATALK_RCD_SCRIPTS}
.for rs in ${ATALK_RCD_SCRIPTS}
RCD_SCRIPT_SRC.${rs}=	${WRKSRC}/output/distrib/initscripts/${rs}
.endfor
.else
MESON_ARGS+=		-Dwith-appletalk=false
.endif

.if !empty(PKG_OPTIONS:Mdebug)
MESON_ARGS+=		-Dwith-debug=true
MESON_ARGS+=		-Dwith-debugging=true
CFLAGS+=		-g3
INSTALL_UNSTRIPPED=	yes
.endif

.if !empty(PKG_OPTIONS:Mdnssd)
.include "../../net/mDNSResponder/buildlink3.mk"
MESON_ARGS+=		-Dwith-zeroconf=true
.else
MESON_ARGS+=		-Dwith-zeroconf=false
.endif

.if !empty(PKG_OPTIONS:Mkerberos)
.include "../../mk/krb5.buildlink3.mk"
PLIST.gssapi=		yes
MESON_ARGS+=		-Dwith-gssapi=true
MESON_ARGS+=		-Dwith-kerberos=true
.else
MESON_ARGS+=		-Dwith-gssapi=false
MESON_ARGS+=		-Dwith-kerberos=false
.endif

.if !empty(PKG_OPTIONS:Mldap)
.include "../../databases/openldap-client/buildlink3.mk"
PLIST.ldap=		yes
MESON_ARGS+=       	-Dwith-ldap=true
.else
MESON_ARGS+=       	-Dwith-ldap=false
.endif

.if !empty(PKG_OPTIONS:Mpam)
.include "../../mk/pam.buildlink3.mk"
PLIST.pam=		yes
MESON_ARGS+=		-Dwith-pam=true
MESSAGE_SRC+=		MESSAGE MESSAGE.pam
.else
MESON_ARGS+=		-Dwith-pam=false
.endif

.if !empty(PKG_OPTIONS:Mspotlight)
.include "../../devel/talloc/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/gnome-tracker/buildlink3.mk"
PLIST.spotlight=	yes
MESON_ARGS+=		-Dwith-dbus-daemon-path=${PREFIX}/bin/dbus-daemon
MESON_ARGS+=		-Dwith-dbus-sysconf-path=${PREFIX}/share/dbus-1
CONF_FILES+=		${EGDIR}/dbus-session.conf \
				${PKG_SYSCONFDIR}/dbus-session.conf
.endif
