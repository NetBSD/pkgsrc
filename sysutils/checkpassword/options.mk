# $NetBSD: options.mk,v 1.1 2017/01/09 04:01:32 schmonz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.checkpassword
PKG_SUPPORTED_OPTIONS+=		checkpassword-suid

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcheckpassword-suid)
SPECIAL_PERMS+=			${CHECKPASSWORD_BIN} ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 4755
.endif
