# $NetBSD: options.mk,v 1.1 2004/08/05 03:04:34 jlam Exp $

# Global and legacy options
.if defined(USE_CUPS) || defined(USE_PAM) || defined(USE_OPENLDAP) || \
    defined(SAMBA_WITH_ADS) || defined(SAMBA_USE_LDAP) || \
    defined(SAMBA_USE_LDAP_COMPAT)
.  if !defined(PKG_OPTIONS.samba)
.    if defined(USE_CUPS) && !empty(USE_CUPS:M[yY][eE][sS])
PKG_OPTIONS.samba+=	cups
.    endif
.    if defined(USE_PAM)
PKG_OPTIONS.samba+=	PAM
.    endif
.    if defined(USE_OPENLDAP) && !empty(USE_OPENLDAP:M[yY][eE][sS])
PKG_OPTIONS.samba+=	ldap
.    endif
.    if defined(SAMBA_WITH_ADS) && !empty(SAMBA_WITH_ADS:M[yY][eE][sS])
PKG_OPTIONS.samba+=	ads
.    endif
.    if defined(SAMBA_USE_LDAP)
PKG_OPTIONS.samba+=	ldap
.    endif
.    if defined(SAMBA_USE_LDAP_COMPAT) && \
        !empty(SAMBA_USE_LDAP_COMPAT:M[yY][eE][sS])
PKG_OPTIONS.samba+=	ldap-compat
.    endif
.  endif
.endif

PKG_OPTIONS_VAR=	PKG_OPTIONS.samba
PKG_SUPPORTED_OPTIONS=	PAM ads cups ldap ldap-compat
.include "../../mk/bsd.options.mk"

###
### Support PAM authentication and build smbpass and winbind PAM modules.
###
.if !empty(PKG_OPTIONS:MPAM)
.  include "../../security/PAM/module.mk"
CONFIGURE_ARGS+=	--with-pam
CONFIGURE_ARGS+=	--with-pam_smbpass
PLIST_SUBST+=		PAM=
.else
PLIST_SUBST+=		PAM="@comment "
.endif

###
### Allow Samba to join as a member server of an Active Directory domain.
###
.if !empty(PKG_OPTIONS:Mads)
.  include "../../mk/krb5.buildlink3.mk"
PKG_OPTIONS+=		ldap
CONFIGURE_ARGS+=	--with-ads
CONFIGURE_ARGS+=	--with-krb5=${KRB5BASE}
.else
CONFIGURE_ARGS+=	--without-ads
CONFIGURE_ARGS+=	--without-krb5
.endif

###
### Native CUPS support for printing
###
.if !empty(PKG_OPTIONS:Mcups)
.  include "../../print/cups/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-cups
.else
CONFIGURE_ARGS+=	--disable-cups
.endif

###
### Support Samba-2.x LDAP password and account databases.
###
.if !empty(PKG_OPTIONS:Mldap-compat)
PKG_OPTIONS+=		ldap
CONFIGURE_ARGS+=	--with-ldapsam
.endif

###
### Support LDAP authentication and storage of Samba account information.
###
.if !empty(PKG_OPTIONS:Mldap)
.  include "../../databases/openldap/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ldap
.else
CONFIGURE_ARGS+=	--without-ldap
.endif

###
### Only Linux supports smbmount for mounting a Samba share into the
### filesystem.
###
.if ${OPSYS} == "Linux"
CONFIGURE_ARGS+=	--with-smbmount
PLIST_SUBST+=		SMBMOUNT=
.else
PLIST_SUBST+=		SMBMOUNT="@comment "
.endif
