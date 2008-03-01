# $NetBSD: options.mk,v 1.3 2008/03/01 05:17:32 jlam Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.kermit
PKG_SUPPORTED_OPTIONS=		kermit-suid-uucp
PKG_OPTIONS_OPTIONAL_GROUPS+=	socks
PKG_OPTIONS_GROUP.socks=	socks4 socks5

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
KFLAGS+=	-DSOCKS
LIBS+=		-L${BUILDLINK_PREFIX.socks4}/lib -lsocks4
.include "../../net/socks4/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Msocks5)
KFLAGS+=	-DSOCKS -DCK_SOCKS5
LIBS+=		-L${BUILDLINK_PREFIX.socks5}/lib -lsocks5
.include "../../net/socks5/buildlink3.mk"
.endif
