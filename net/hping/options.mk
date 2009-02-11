# $NetBSD: options.mk,v 1.2 2009/02/11 08:06:17 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.hping
PKG_SUPPORTED_OPTIONS=	hping-suid

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mhping-suid)
SPECIAL_PERMS+=	sbin/hping2 ${SETUID_ROOT_PERMS}
.endif
