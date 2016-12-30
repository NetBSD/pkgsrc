# $NetBSD: options.mk,v 1.13 2016/12/30 23:09:41 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.xemacs
PKG_SUPPORTED_OPTIONS+=		ldap xface canna debug
#PKG_SUPPORTED_OPTIONS+=	esound

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		ldap
.if !empty(PKG_OPTIONS:Mldap)
PLIST.ldap=		yes
CONFIGURE_ARGS+=	--with-ldap
.  include "../../databases/openldap-client/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-ldap
.endif

.if !empty(PKG_OPTIONS:Mxface)
CONFIGURE_ARGS+=	--with-xface
.  include "../../mail/faces/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-xface
.endif

.if !empty(PKG_OPTIONS:Mcanna)
.  include "../../inputmethod/canna-lib/buildlink3.mk"
CONFIGURE_ARGS+=	--with-canna
.else
CONFIGURE_ARGS+=	--without-canna
.endif

.if !empty(PKG_OPTIONS:Mesound)
.  include "../../audio/esound/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--with-sound=none
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug=yes --with-debug
.endif
