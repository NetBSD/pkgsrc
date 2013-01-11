# $NetBSD: options.mk,v 1.24 2013/01/11 12:41:16 jperkin Exp $

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS_VAR=	PKG_OPTIONS.openssh
PKG_SUPPORTED_OPTIONS=	kerberos hpn-patch ldap pam

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mkerberos)
.  include "../../mk/krb5.buildlink3.mk"
CONFIGURE_ARGS+=	--with-kerberos5=${KRB5BASE:Q}
.  if ${KRB5_TYPE} == "mit-krb5"
CONFIGURE_ENV+=		ac_cv_search_k_hasafs=no
.  endif
.endif

.if !empty(PKG_OPTIONS:Mhpn-patch)
PATCHFILES=		openssh-5.8p1-hpn13v11.diff.gz
PATCH_SITES=		http://www.shatow.net/freebsd/
PATCH_DIST_STRIP=	-p1
.endif

.if !empty(PKG_OPTIONS:Mpam)
.include "../../mk/pam.buildlink3.mk"
CONFIGURE_ARGS+=	--with-pam
PLIST_SRC+=		${.CURDIR}/PLIST.pam
MESSAGE_SRC+=		${.CURDIR}/MESSAGE.pam
MESSAGE_SUBST+=		EGDIR=${EGDIR}
.endif

.if !empty(PKG_OPTIONS:Mldap)
.include "../../databases/openldap-client/buildlink3.mk"
USE_TOOLS+=		autoconf
CONFIGURE_ARGS+=	--with-ldap
LPK_CONFS+=		lpk-user-example.txt		\
			openssh-lpk_openldap.schema	\
			openssh-lpk_sun.schema
PLIST_SRC+=		${.CURDIR}/PLIST.ldap

LPK_VERS=		0.3.14
OPENSSH_VERS=		${DISTNAME:S/openssh-//}
PATCHFILES=		openssh-lpk-${OPENSSH_VERS}-${LPK_VERS}.patch.gz
PATCH_SITES=		http://gentoo.mirrors.tera-byte.com/distfiles/
PATCH_DIST_STRIP=	-p1
.endif
