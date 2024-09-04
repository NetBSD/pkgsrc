# $NetBSD: options.mk,v 1.7 2024/09/04 12:34:48 gdt Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.kermit
PKG_SUPPORTED_OPTIONS=		kermit-suid-uucp ssl kerberos
PKG_OPTIONS_OPTIONAL_GROUPS+=	socks
PKG_OPTIONS_GROUP.socks=	socks4 dante

.include "../../mk/bsd.options.mk"

###
### Install the kermit binary as a setuid-uucp binary.
###
.if !empty(PKG_OPTIONS:Mkermit-suid-uucp)
PKG_GROUPS+=		${UUCP_GROUP}
PKG_USERS+=		${UUCP_USER}:${UUCP_GROUP}
PKG_GROUPS_VARS+=	UUCP_GROUP
PKG_USERS_VARS+=	UUCP_USER
SPECIAL_PERMS+=		bin/kermit ${UUCP_USER} ${UUCP_GROUP} 4555
.endif

###
### SOCKS firewall support.
###
.if !empty(PKG_OPTIONS:Msocks4)
KFLAGS+=	-DSOCKS -DCK_SOCKS
LIBS+=		-L${BUILDLINK_PREFIX.dante}/lib -lsocks
.include "../../net/dante/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Mdante)
KFLAGS+=	-DSOCKS -DCK_SOCKS
LIBS+=		-L${BUILDLINK_PREFIX.dante}/lib -lsocks
.include "../../net/dante/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mkerberos)
BUILD_TARGET_OPTIONS+=	+krb5
# \todo Change to krb5.buildlink3.mk (allowing heimdal), or document why not.
.include "../../security/mit-krb5/buildlink3.mk"
K5INC=		-I${WRKDIR}/.buildlink/include
K5LIB=		-L${WRKDIR}/.buildlink/lib ${COMPILER_RPATH_FLAG}${WRKDIR}/.buildlink/lib
MAKE_ENV+=	K5INC=${K5INC:Q} K5LIB=${K5LIB:Q}
.endif

.if !empty(PKG_OPTIONS:Mssl)
BUILD_TARGET_OPTIONS+=	+ssl
.include "../../security/openssl/buildlink3.mk"
# Set to empty
SSLINC=		-I${WRKDIR}/.buildlink/include
SSLLIB=		-L${WRKDIR}/.buildlink/lib ${COMPILER_RPATH_FLAG}${WRKDIR}/.buildlink/lib
MAKE_ENV+=	SSLINC=${SSLINC:Q} SSLLIB=${SSLLIB:Q}
.endif
