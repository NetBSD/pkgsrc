# $NetBSD: options.mk,v 1.2 2024/02/28 04:14:16 schmonz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.bincimap
PKG_SUPPORTED_OPTIONS+=		pam

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpam)
DEPENDS+=			checkpassword-pam>=0.99nb1:../../sysutils/checkpassword-pam
.else
DEPENDS+=			checkpassword>=0.90nb1:../../sysutils/checkpassword
.endif
