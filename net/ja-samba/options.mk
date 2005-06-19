# $NetBSD: options.mk,v 1.4 2005/06/19 18:38:40 taca Exp $

# Global and legacy options

PKG_OPTIONS_VAR=	PKG_OPTIONS.ja-samba
PKG_SUPPORTED_OPTIONS=	pam cups ldap-compat ssl
.include "../../mk/bsd.options.mk"

###
### Support PAM authentication and build smbpass and winbind PAM modules.
###
.if !empty(PKG_OPTIONS:Mpam)
.  include "../../mk/pam.buildlink3.mk"
CONFIGURE_ARGS+=	--with-pam
CONFIGURE_ARGS+=	--with-pam_smbpass
PLIST_SUBST+=		PAM=
.else
CONFIGURE_ARGS+=	--without-pam
PLIST_SUBST+=		PAM="@comment "
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
### Support LDAP password and account databases.
###
.if !empty(PKG_OPTIONS:Mldap-compat)
.  include "../../databases/openldap/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ldapsam
PLIST_SUBST+=		SAMBA_LDAP=""
.else
PLIST_SUBST+=		SAMBA_LDAP="@comment "
MESSAGE_SRC=		${.CURDIR}/MESSAGE.smbpasswd
SMBPASSWD_FILE=		/dev/null ${SAMBA_PRIVATE}/smbpasswd		\
			${ROOT_USER} ${ROOT_GROUP} 0600
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

###
### Use of SSL function
###
.if !empty(PKG_OPTIONS:Mssl)
.include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ssl
CONFIGURE_ARGS+=	--with-sslinc=${SSLBASE}
CFLAGS+=		-I${SSLBASE}/include/openssl	# ssl.h, err.h
.else
CONFIGURE_ARGS+=	--without-ssl
.endif

###
### Determine the proper name for the winbind and WINS NSS modules.
###
NSS_WINBIND.${OPSYS}?=  libnss_winbind.so
NSS_WINS.${OPSYS}?=     libnss_wins.so

NSS_WINBIND.AIX=        WINBIND
NSS_WINS.AIX=           # empty

NSS_WINBIND.DragonFly=	# empty
NSS_WINS.DragonFly=	# empty

NSS_WINBIND.IRIX=       libns_winbind.so
NSS_WINS.IRIX=          libns_wins.so

.if !empty(MACHINE_PLATFORM:MFreeBSD-5.*)
NSS_WINBIND.FreeBSD=    nss_winbind.so
NSS_WINS.FreeBSD=       nss_wins.so
.endif

NSS_WINBIND=            ${NSS_WINBIND.${OPSYS}}
NSS_WINS=               ${NSS_WINS.${OPSYS}}
