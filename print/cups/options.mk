# $NetBSD: options.mk,v 1.2 2008/04/12 22:43:09 jlam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.cups
PKG_SUPPORTED_OPTIONS=	dnssd kerberos pam slp
PKG_SUGGESTED_OPTIONS=	dnssd kerberos slp
.include "../../mk/bsd.options.mk"

PLIST_VARS+=		pam
.if !empty(PKG_OPTIONS:Mpam)
.  include "../../mk/pam.buildlink3.mk"
CONFIGURE_ARGS+=	--enable-pam
MESSAGE_SRC=		${PKGDIR}/MESSAGE
MESSAGE_SRC+=		${PKGDIR}/MESSAGE.pam
PLIST.pam=		yes
.else
CONFIGURE_ARGS+=	--disable-pam
MESSAGE_SRC=		${.CURDIR}/MESSAGE
.endif

.if !empty(PKG_OPTIONS:Mslp)
.include "../../net/openslp/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-slp
.else
CONFIGURE_ARGS+=	--disable-slp
.endif

.if !empty(PKG_OPTIONS:Mkerberos)
.include "../../mk/krb5.buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mdnssd)
.include "../../net/mDNSResponder/buildlink3.mk"
.endif
