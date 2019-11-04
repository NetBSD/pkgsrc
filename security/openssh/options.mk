# $NetBSD: options.mk,v 1.38 2019/11/04 21:12:56 rillig Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.openssh
PKG_SUPPORTED_OPTIONS=	editline kerberos openssl pam legacymodsz
PKG_SUGGESTED_OPTIONS=	editline openssl

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
PKG_SUGGESTED_OPTIONS+=	pam
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mopenssl)
.include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ssl-dir=${SSLBASE:Q}
.else
CONFIGURE_ARGS+=	--without-openssl
.endif

.if !empty(PKG_OPTIONS:Mkerberos)
.  include "../../mk/krb5.buildlink3.mk"
CONFIGURE_ARGS+=	--with-kerberos5=${KRB5BASE}
.  if ${KRB5_TYPE} == "mit-krb5"
CONFIGURE_ENV+=		ac_cv_search_k_hasafs=no
.  endif
.endif

.if !empty(PKG_OPTIONS:Mlegacymodsz)
CONFIGURE_ARGS+=	CPPFLAGS="${CPPFLAGS} -DSSH_RSA_INSECURE_LEGACY_MIN_MOD_SZ=768"
.endif

#.if !empty(PKG_OPTIONS:Mhpn-patch)
#PATCHFILES=		openssh-7.1p1-hpn-20150822.diff.bz2
#PATCH_SITES=		ftp://ftp.NetBSD.org/pub/NetBSD/misc/openssh/
#PATCH_DIST_STRIP=	-p1
#.endif

PLIST_VARS+=	pam

.if !empty(PKG_OPTIONS:Mpam)
.include "../../mk/pam.buildlink3.mk"
CONFIGURE_ARGS+=	--with-pam
MESSAGE_SRC+=		${.CURDIR}/MESSAGE.pam
MESSAGE_SUBST+=		EGDIR=${EGDIR}
.  if ${OPSYS} == "Linux"
PLIST.pam=	yes
.  endif
.endif

.if !empty(PKG_OPTIONS:Meditline)
.include "../../devel/editline/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libedit=${BUILDLINK_PREFIX.editline}
.endif
