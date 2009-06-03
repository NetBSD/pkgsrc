# $NetBSD: options.mk,v 1.3 2009/06/03 10:20:59 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.cups
PKG_OPTIONS_OPTIONAL_GROUPS=	pdftops
PKG_OPTIONS_GROUP.pdftops=	gs poppler xpdf
PKG_SUPPORTED_OPTIONS=	dnssd kerberos pam slp
PKG_SUGGESTED_OPTIONS=	dnssd kerberos poppler slp

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		pdftops

.if !empty(PKG_OPTIONS:Mdnssd)
.include "../../net/mDNSResponder/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mgs)
PLIST.pdftops=	yes
DEPENDS+=	ghostscript-[0-9]*:../../print/ghostscript
.endif

.if !empty(PKG_OPTIONS:Mkerberos)
.include "../../mk/krb5.buildlink3.mk"
.endif

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

.if !empty(PKG_OPTIONS:Mpoppler)
PLIST.pdftops=	yes
DEPENDS+=	poppler-utils-[0-9]*:../../print/poppler-utils
.endif

.if !empty(PKG_OPTIONS:Mslp)
.include "../../net/openslp/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-slp
.else
CONFIGURE_ARGS+=	--disable-slp
.endif

.if !empty(PKG_OPTIONS:Mxpdf)
PLIST.pdftops=	yes
DEPENDS+=	xpdf-[0-9]*:../../print/xpdf
.endif
