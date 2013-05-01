# $NetBSD: options.mk,v 1.25 2013/05/01 19:58:25 imil Exp $

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS_VAR=	PKG_OPTIONS.openssh
PKG_SUPPORTED_OPTIONS=	kerberos hpn-patch pam

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mkerberos)
.  include "../../mk/krb5.buildlink3.mk"
CONFIGURE_ARGS+=	--with-kerberos5=${KRB5BASE:Q}
.  if ${KRB5_TYPE} == "mit-krb5"
CONFIGURE_ENV+=		ac_cv_search_k_hasafs=no
.  endif
.endif

.if !empty(PKG_OPTIONS:Mhpn-patch)
PATCHFILES=		openssh-6.2p1-hpn13v14.diff
PATCH_SITES=		ftp://ftp.NetBSD.org/pub/NetBSD/misc/imil/openssh/
PATCH_DIST_STRIP=	-p1
.endif

.if !empty(PKG_OPTIONS:Mpam)
.include "../../mk/pam.buildlink3.mk"
CONFIGURE_ARGS+=	--with-pam
PLIST_SRC+=		${.CURDIR}/PLIST.pam
MESSAGE_SRC+=		${.CURDIR}/MESSAGE.pam
MESSAGE_SUBST+=		EGDIR=${EGDIR}
.endif
