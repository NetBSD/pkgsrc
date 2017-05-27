# $NetBSD: options.mk,v 1.3.6.1 2017/05/27 19:01:15 bsiegert Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.samba4
PKG_SUPPORTED_OPTIONS=	ads fam ldap pam winbind # cups # cups option is broken for me.
PKG_SUGGESTED_OPTIONS=	ldap pam winbind

.include "../../mk/bsd.fast.prefs.mk"

SAMBA_ACL_OPSYS=	AIX Darwin FreeBSD HPUX IRIX Linux OSF1 SunOS
.if !empty(SAMBA_ACL_OPSYS:M${OPSYS})
PKG_SUPPORTED_OPTIONS+=	acl
.endif

.if empty(MACHINE_PLATFORM:MDarwin-1[1-9].*)
PKG_SUGGESTED_OPTIONS+=	ads
.endif

.include "../../mk/bsd.options.mk"

###
### Access Control List support.
###
.if !empty(PKG_OPTIONS:Macl)
CONFIGURE_ARGS+=	--with-acl-support
.else
CONFIGURE_ARGS+=	--without-acl-support
.endif

###
### Allow Samba to join as a member server of an Active Directory domain.
###
.if !empty(PKG_OPTIONS:Mads)
CONFIGURE_ARGS+=	--with-ads
.else
CONFIGURE_ARGS+=	--without-ads
.endif

###
### Native CUPS support for providing printing services.
###
PLIST_VARS+=		cups
.if !empty(PKG_OPTIONS:Mcups)
.  include "../../print/cups/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-cups
PLIST.cups=		yes
INSTALLATION_DIRS+=	libexec/cups/backend
.else
CONFIGURE_ARGS+=	--disable-cups
.endif

###
### File Alteration Monitor support.
###
PLIST_VARS+=		fam
.if !empty(PKG_OPTIONS:Mfam)
.  include "../../mk/fam.buildlink3.mk"
CONFIGURE_ARGS+=	--with-fam
PLIST.fam=		yes
.else
CONFIGURE_ARGS+=	--without-fam
.endif

###
### Support LDAP authentication and storage of Samba account information.
###
PLIST_VARS+=		ldap
# Active Directory requires ldap
.if !empty(PKG_OPTIONS:Mldap) || !empty(PKG_OPTIONS:Mads)
.  include "../../databases/openldap-client/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ldap
PLIST.ldap=		yes
.else
CONFIGURE_ARGS+=	--without-ldap
.endif

###
### Support PAM authentication and build smbpass and winbind PAM modules.
###
PLIST_VARS+=		pam
.if !empty(PKG_OPTIONS:Mpam)
.  include "../../mk/pam.buildlink3.mk"

CONFIGURE_ARGS+=	--with-pam
CONFIGURE_ARGS+=	--with-pammodulesdir=${SMB_PAMMODULES}
PLIST.pam=		yes
INSTALLATION_DIRS+=	${EGDIR}/pam_smbpass
.else
CONFIGURE_ARGS+=	--without-pam
.endif

###
### Support querying a PDC for domain user and group information, e.g.,
### through NSS or PAM.
###
PLIST_VARS+=		winbind
.if !empty(PKG_OPTIONS:Mwinbind)
CONFIGURE_ARGS+=	--with-winbind
PLIST.winbind=		yes
.else
CONFIGURE_ARGS+=	--without-winbind
.endif
