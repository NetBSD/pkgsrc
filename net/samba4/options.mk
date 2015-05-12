# $NetBSD: options.mk,v 1.1 2015/05/12 12:19:52 ryoon Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.samba4
PKG_SUPPORTED_OPTIONS=	fam pam winbind # cups # cups option is broken for me.
PKG_SUGGESTED_OPTIONS=	pam winbind

.include "../../mk/bsd.fast.prefs.mk"

SAMBA_ACL_OPSYS=	AIX Darwin FreeBSD HPUX IRIX Linux OSF1 SunOS
.if !empty(SAMBA_ACL_OPSYS:M${OPSYS})
PKG_SUPPORTED_OPTIONS+=	acl
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
### Support PAM authentication and build smbpass and winbind PAM modules.
###
PLIST_VARS+=		pam
.if !empty(PKG_OPTIONS:Mpam)
.  include "../../mk/pam.buildlink3.mk"

CONFIGURE_ARGS+=	--with-pam
CONFIGURE_ARGS+=	--with-pam_smbpass
CONFIGURE_ARGS+=	--with-pammodulesdir=${SMB_PAMMODULES}
PLIST.pam=		yes
INSTALLATION_DIRS+=	${EGDIR}/pam_smbpass

.PHONY: samba-pam-smbpass-install
post-install: samba-pam-smbpass-install
samba-pam-smbpass-install:
	cd ${WRKSRC}/source3/pam_smbpass/samples; for f in [a-z]*; do		\
		${INSTALL_DATA} $${f} \
			${DESTDIR}${PREFIX}/${EGDIR}/pam_smbpass/$${f};	\
	done
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
