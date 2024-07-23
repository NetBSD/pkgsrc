# $NetBSD: options.mk,v 1.50 2024/07/23 06:38:22 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.openssh
PKG_SUPPORTED_OPTIONS=	editline fido kerberos openssl pam openssh-legacymodsz
PKG_SUGGESTED_OPTIONS=	editline openssl

# remove after pkgsrc-2024Q3
PKG_OPTIONS_LEGACY_OPTS+=	legacymodsz:openssh-legacymodsz

.include "../../mk/bsd.prefs.mk"

.include "../../security/libfido2/platform.mk"

.if ${PLATFORM_SUPPORTS_FIDO2:tl} != "no"
PKG_SUGGESTED_OPTIONS+=	fido
.endif

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "Darwin"
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

.if !empty(PKG_OPTIONS:Mopenssh-legacymodsz)
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
.  if ${OPSYS} == "Linux"
PLIST.pam=	yes
.  endif
.endif

.if !empty(PKG_OPTIONS:Meditline)
.include "../../devel/editline/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libedit=${BUILDLINK_PREFIX.editline}
.endif

.if !empty(PKG_OPTIONS:Mfido)
.include "../../security/libfido2/buildlink3.mk"
CONFIGURE_ARGS+=	--with-security-key-builtin
.endif
