# $NetBSD: options.mk,v 1.12 2020/11/12 06:37:18 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.samba4
PKG_SUPPORTED_OPTIONS=	ads avahi fam ldap pam winbind # cups # cups option is broken for me.
PKG_SUGGESTED_OPTIONS=	avahi ldap pam winbind

.include "../../mk/bsd.fast.prefs.mk"

SAMBA_ACL_OPSYS=	AIX Darwin FreeBSD HPUX IRIX Linux NetBSD OSF1 SunOS
.if !empty(SAMBA_ACL_OPSYS:M${OPSYS})
PKG_SUPPORTED_OPTIONS+=	acl
.endif

.if empty(MACHINE_PLATFORM:MDarwin-1[1-9].*)
PKG_SUGGESTED_OPTIONS+=	ads
.endif

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		ads cups fam ldap pam winbind

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
PLIST.ads=		yes
.else
CONFIGURE_ARGS+=	--without-ads
.endif

###
### Native CUPS support for providing printing services.
###
.if !empty(PKG_OPTIONS:Mcups)
.  include "../../print/cups-base/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-cups
PLIST.cups=		yes
INSTALLATION_DIRS+=	libexec/cups/backend
.else
CONFIGURE_ARGS+=	--disable-cups
.endif

###
### File Alteration Monitor support.
###
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
.if !empty(PKG_OPTIONS:Mwinbind)
CONFIGURE_ARGS+=	--with-winbind
PLIST.winbind=		yes
WINBINDD_RCD_SCRIPT=	winbindd
.else
CONFIGURE_ARGS+=	--without-winbind
.endif

###
### Avahi DNS Service Discovery.
###
.if !empty(PKG_OPTIONS:Mavahi)
.include "../../net/avahi/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-avahi
.else
CONFIGURE_ARGS+=	--disable-avahi
.endif
