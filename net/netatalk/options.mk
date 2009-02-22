# $NetBSD: options.mk,v 1.1 2009/02/22 07:35:16 taca Exp $
#
PKG_OPTIONS_VAR=	PKG_OPTIONS.netatalk
PKG_SUPPORTED_OPTIONS=	cjk cups kerberos pam slp

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcjk)
# CJK(Chinese/Japanese/Korean) patch.
#
# http://www003.upp.so-net.ne.jp/hat/netatalk/cjk.html
#
PATCHFILES+=	netatalk-2.0.3-cjk-2b.patch.gz
PATCH_SITES+=	http://www003.upp.so-net.ne.jp/hat/files/
PATCH_DIST_STRIP.netatalk-2.0.3-cjk-2b.patch.gz=	-p1
.endif

.if !empty(PKG_OPTIONS:Mcups)
.include "../../print/cups/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-cups
.else
CONFIGURE_ARGS+=	--disable-cups
.endif

PLIST_VARS+=		gssapi
.if !empty(PKG_OPTIONS:Mkerberos)
.include "../../mk/krb5.buildlink3.mk"
CONFIGURE_ARGS+=	--with-gssapi --enable-krbV-uam
CONFIGURE_ENV+=		GSSAPI_LIBS="-lkrb5 -lroken -lasn1 -lcrypto -lcom_err"
PLIST.gssapi=		yes
.else
CONFIGURE_ARGS+=	--without-gssapi
.endif

PLIST_VARS+=		pam
.if !empty(PKG_OPTIONS:Mpam)
.include "../../mk/pam.buildlink3.mk"
CONFIGURE_ARGS+=	--with-pam
PLIST.pam=		yes
MESSAGE_SRC+=		MESSAGE MESSAGE.pam
.else
CONFIGURE_ARGS+=	--without-pam
.endif

.if !empty(PKG_OPTIONS:Mslp)
.include "../../net/openslp/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-srvloc
.else
CONFIGURE_ARGS+=	--disable-srvloc
.endif
