# $NetBSD: options.mk,v 1.5 2010/05/20 09:35:58 sbd Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.cups
PKG_OPTIONS_REQUIRED_GROUPS=	pdftops
PKG_OPTIONS_GROUP.pdftops=	ghostscript poppler
PKG_SUPPORTED_OPTIONS=	dnssd kerberos pam slp
PKG_SUGGESTED_OPTIONS=	dnssd kerberos poppler slp
PKG_OPTIONS_LEGACY_OPTS+=	xpdf:poppler gs:ghostscript

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdnssd)
.include "../../net/mDNSResponder/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-dnssd
.else
CONFIGURE_ARGS+=	--disable-dnssd
.endif

.if !empty(PKG_OPTIONS:Mghostscript)
USE_TOOLS+=	gs:run
CONFIGURE_ARGS+=	--with-pdftops=gs
CONFIGURE_ENV+=		ac_cv_path_CUPS_GHOSTSCRIPT=${TOOLS_PATH.gs}
.endif

.if !empty(PKG_OPTIONS:Mkerberos)
.include "../../mk/krb5.buildlink3.mk"
CONFIGURE_ARGS+=	--enable-gssapi
.else
CONFIGURE_ARGS+=	--disable-gssapi
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
FIND_PREFIX:=	POPPLERDIR=poppler-utils
.include "../../mk/find-prefix.mk"
DEPENDS+=	poppler-utils-[0-9]*:../../print/poppler-utils
CONFIGURE_ARGS+=	--with-pdftops=pdftops
CONFIGURE_ENV+=		ac_cv_path_CUPS_PDFTOPS=${POPPLERDIR}/bin/pdftops
.endif

.if !empty(PKG_OPTIONS:Mslp)
.include "../../net/openslp/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-slp
.else
CONFIGURE_ARGS+=	--disable-slp
.endif
