# $NetBSD: options.mk,v 1.1.1.1 2011/11/30 23:47:29 pettai Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.tacacs-shrubbery
PKG_SUPPORTED_OPTIONS=	tacacs-shrubbery-acls-support tacacs-shrubbery-drop-root-privileges tcpwrappers skey
PKG_SUGGESTED_OPTIONS=	tacacs-shrubbery-acls-support tcpwrappers skey

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mtacacs-shrubbery-acls-support)
CONFIGURE_ARGS+=	--enable-acls
.else
CONFIGURE_ARGS+=	--disable-acls
.endif

.if !empty(PKG_OPTIONS:Mtacacs-shrubbery-drop-root-privileges)
# tac_plus code requires numeric UID, GID
DEFAULT_TACACS_USER!=	${ID} -u nobody
DEFAULT_TACACS_GROUP!=	${ID} -g nobody
TACACS_USER?=		${DEFAULT_TACACS_USER}
TACACS_GROUP?=		${DEFAULT_TACACS_GROUP}
PKG_USERS=		${TACACS_USER}:${TACACS_GROUP}
PKG_GROUPS=		${TACACS_GROUP}
CONFIGURE_ARGS+=	--with-userid=${TACACS_USER:Q}
CONFIGURE_ARGS+=	--with-groupid=${TACACS_GROUP:Q}
.endif

.if !empty(PKG_OPTIONS:Mtcpwrappers)
CONFIGURE_ARGS+=	--with-libwrap=${BUILDLINK_PREFIX.tcp_wrappers}
. include "../../security/tcp_wrappers/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-libwrap
.endif

.if !empty(PKG_OPTIONS:Mskey)
CONFIGURE_ARGS+=	--with-skey=${BUILDLINK_PREFIX.skey}
. include "../../security/skey/buildlink3.mk"
. if (defined(IS_BUILTIN.skey) && ${IS_BUILTIN.skey} == no ) || ${OPSYS} == "OpenBSD"
# pkgsrc's version uses three arguments only, as does OpenBSD's
CPPFLAGS+=		-DOLDSKEY
. endif
.else
CONFIGURE_ARGS+=	--without-skey
.endif
